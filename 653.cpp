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
    bool findTarget(TreeNode* root, int k) {
        vector<int> array;
        inOrderConverseList(root, array);
        int left = 0;
        int right = array.size() - 1;
        bool check = false;
        while(left < right) {
            int sum = array[left] + array[right];
            if(sum == k) {
                check = true;
                break;
            } else if (sum < k) {
                left++;
            } else {
                right--;
            }
        }
        return check;
    }

    void inOrderConverseList(TreeNode* root, vector<int>& array) {
        if (root) {
            inOrderConverseList(root->left, array);
            array.push_back(root->val);
            inOrderConverseList(root->right, array);
        }
    }
};
