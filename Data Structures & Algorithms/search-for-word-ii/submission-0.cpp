class TrieNode {
public:
    TrieNode* children[26];
    string word;
    TrieNode() {
        for (int i = 0; i < 26; i++) children[i] = nullptr;
        word = "";
    }
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* root = new TrieNode();
        for (const string& w : words) {
            TrieNode* node = root;
            for (char c : w) {
                int idx = c - 'a';
                if (!node->children[idx]) {
                    node->children[idx] = new TrieNode();
                }
                node = node->children[idx];
            }
            node->word = w;
        }
        
        vector<string> res;
        int m = board.size(), n = board[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                dfs(board, i, j, root, res);
            }
        }
        return res;
    }

private:
    void dfs(vector<vector<char>>& board, int i, int j, TrieNode* node, vector<string>& res) {
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size()) return;
        char c = board[i][j];
        if (c == '#' || !node->children[c - 'a']) return;
        
        node = node->children[c - 'a'];
        if (!node->word.empty()) {
            res.push_back(node->word);
            node->word = "";
        }
        
        board[i][j] = '#';
        dfs(board, i + 1, j, node, res);
        dfs(board, i - 1, j, node, res);
        dfs(board, i, j + 1, node, res);
        dfs(board, i, j - 1, node, res);
        board[i][j] = c;
    }
};