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
    vector<double> averageOfLevels(TreeNode* root) {
        queue<pair<TreeNode*, int>> nodeLevel;
        nodeLevel.push(make_pair(root, 0));
        vector<double> res;
        int curDepth = 0;
        long long levelsum = 0;
        int levelcount = 0;

        while(!nodeLevel.empty()) {
            cout << nodeLevel.size() << " ";
            pair<TreeNode*, int> cur = nodeLevel.front();
            nodeLevel.pop();
            TreeNode* node = cur.first;
            cout << node->val << " ";
            int depth = cur.second;
            if (depth == curDepth) {
                levelsum += node->val;
                levelcount++;
            } else {
                curDepth = depth;
                res.push_back((double)levelsum/levelcount);
                levelsum = node->val;
                levelcount = 1;
            }
            if (node->left != nullptr)
                nodeLevel.push(make_pair(node->left, depth + 1));
            if (node->right != nullptr)
                nodeLevel.push(make_pair(node->right, depth + 1));
        }
        res.push_back((double)levelsum/levelcount);
        return res;
    }
};
