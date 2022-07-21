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
    void recursion(TreeNode* root, vector<int>&ans, int lvl){
        if(root==NULL) return ;
        if(ans.size()==lvl) ans.push_back(root->val);
        recursion(root->right,ans,lvl+1);
        recursion(root->left,ans,lvl+1);
    }
    vector<int> rightSideView(TreeNode* root) {
       int level = 0;
        vector<int>rightEle;
        recursion(root,rightEle,level);
        return rightEle;
    }
};