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
    int minDiffInBST(TreeNode* root) {
        int minDiff = INT_MAX;
        int minu = root->val;
        int max = root->val;
        helper(root, minu, max, minDiff);

        return minDiff;
    }

    void helper(TreeNode* root, int& minu, int& max, int& minDiff) {
        if (root->left != nullptr) {
            int tempmax = root->left->val;
            minu = root->left->val;
            helper(root->left, minu, tempmax, minDiff);
            minDiff = min(root->val - tempmax, minDiff);
        }
        if (root->right != nullptr) {
            int tempmin = root->right->val;
            max = root->right->val;
            helper(root->right, tempmin, max, minDiff);
            minDiff = min(tempmin - root->val, minDiff);
        }
    }
};
