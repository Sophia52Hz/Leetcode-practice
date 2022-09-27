#include <vector>
#include<queue>
#include<iostream>

using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
class Solution {
    int maxLevel = 0;

    int maxDepth(TreeNode* root) {
        if (!root) {
            return 0;
        }
        dfs(root, 1);
        return maxLevel;
    }

    void dfs(TreeNode* root, int level) {
        if (!root )
            return;
        if (level > maxLevel) maxLevel = level;
        dfs(root->left, level + 1);
        dfs(root->right, level + 1);
    }
};