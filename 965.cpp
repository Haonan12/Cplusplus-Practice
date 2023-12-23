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
    bool isUnivalTree(TreeNode* root) {
        if (root == nullptr) {
            return true;
        } else {
            return isUnivalTreeHelper(root->left, root->val) && isUnivalTreeHelper(root->right, root->val);
        }
    }

    bool isUnivalTreeHelper(TreeNode* root, int i) {
        if (root == nullptr) {
            return true;
        } else {
            return root->val == i && isUnivalTreeHelper(root->left, root->val) && isUnivalTreeHelper(root->right, root->val);
        } 
    }
};
