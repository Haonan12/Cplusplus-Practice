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
    bool isCousins(TreeNode* root, int x, int y) {
        queue<pair<TreeNode*, int>> depthLevel;
        if (root == nullptr) {
            return false;
        }
        depthLevel.push(make_pair(root->left, 1));
        depthLevel.push(make_pair(root->right, 1));
        int firstFound = 0;
        bool result = false;
        while (!depthLevel.empty()) {
            int f1 = checkMatch(depthLevel, firstFound, x, y);
            if (f1 == -1) {
                break;
            }
            int f2 = checkMatch(depthLevel, firstFound, x, y);

            if (f1 > 0 && f2 > 0) {
                break;
            } else if (f1 > 0 || f2 > 0) {
                if (firstFound == 0) {
                    firstFound = max(f1, f2);
                } else {
                    result = (firstFound == max(f1, f2));
                    break;
                }
            }
        }

        return result;
    }

    int checkMatch(queue<pair<TreeNode*, int>>& depthLevel, int firstFound, int x, int y) {
        pair<TreeNode*, int> p = depthLevel.front();
        depthLevel.pop();
        TreeNode* cur = p.first;
        int depth = p.second;
        int result = 0;
        if (firstFound > 0 && depth > firstFound) {
            return -1;
        }
        if (cur == nullptr) {
            return 0;
        } 
        if (cur->val == x || cur->val == y) {
            result = depth;
        } 

        depthLevel.push(make_pair(cur->left, depth + 1));
        depthLevel.push(make_pair(cur->right, depth + 1));
        return result;
    }
};
