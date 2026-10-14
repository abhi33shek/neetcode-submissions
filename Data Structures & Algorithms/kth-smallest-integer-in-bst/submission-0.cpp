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
class Solution {
public:
    int ans = -1;
    
    int kthSmallest(TreeNode* root, int k) {
        int count = 0;
        traverse(root, count, k);
        return ans;
    }
    
private:
    void traverse(TreeNode* node, int& count, int k) {
        if (!node) return;
        
        traverse(node->left, count, k);
        
        count++;
        if (count == k) {
            ans = node->val;
            return;
        }
        
        traverse(node->right, count, k);
    }
};
