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
public:
/* on the base of levelOrder travel, we should record the number of the level to split the ans,
   so we could add one loop when we travel to distcint the level,
   the number of level is the size of queue.
*/
vector<vector< int > > levelOrder(TreeNode* root) {
    vector<vector< int > > res;
    if(!root) return res;
    queue<TreeNode*> qu;
    qu.push(root);
    while(!qu.empty())
    {
        vector<int> tmp;
        int len=qu.size();
        for(int i=0;i<len;i++){
            TreeNode* node=qu.front();
            qu.pop();
            tmp.push_back(node->val);
            if(node->left) qu.push(node->left);
            if(node->right) qu.push(node->right);
        }
    res.push_back(tmp);
    }
    return res;
    }
};