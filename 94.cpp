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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        helpTraversal(root, &result);
        return result;
    }

    void helpTraversal(TreeNode* root, vector<int>* array) {
        if (root != nullptr) {
            helpTraversal(root->left, array);
            array->push_back(root->val);
            helpTraversal(root->right, array);
        }
    }
};
