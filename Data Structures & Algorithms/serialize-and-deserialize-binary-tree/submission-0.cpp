/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Codec {
public:
    string serialize(TreeNode* root) {
        if (!root) return "";
        vector<string> tokens;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if (!node) {
                tokens.push_back("#");
                continue;
            }
            tokens.push_back(to_string(node->val));
            q.push(node->left);
            q.push(node->right);
        }

        string res;
        for (int i = 0; i < (int)tokens.size(); i++) {
            if (i > 0) res += ',';
            res += tokens[i];
        }
        return res;
    }

    TreeNode* deserialize(string data) {
        if (data.empty()) return nullptr;
        vector<string> tokens = split(data);
        TreeNode* root = new TreeNode(stoi(tokens[0]));
        queue<TreeNode*> q;
        q.push(root);

        int i = 1;
        while (!q.empty() && i < (int)tokens.size()) {
            TreeNode* parent = q.front();
            q.pop();

            if (i < (int)tokens.size() && tokens[i] != "#") {
                parent->left = new TreeNode(stoi(tokens[i]));
                q.push(parent->left);
            }
            i++;

            if (i < (int)tokens.size() && tokens[i] != "#") {
                parent->right = new TreeNode(stoi(tokens[i]));
                q.push(parent->right);
            }
            i++;
        }
        return root;
    }

private:
    vector<string> split(const string& str) {
        vector<string> res;
        string cur;
        for (char c : str) {
            if (c == ',') {
                res.push_back(cur);
                cur.clear();
            } else {
                cur += c;
            }
        }
        res.push_back(cur);
        return res;
    }
};