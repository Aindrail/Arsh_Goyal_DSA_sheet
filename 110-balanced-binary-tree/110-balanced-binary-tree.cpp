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
    int CheckBal(TreeNode* root){
        if(root==NULL)return 0;
        int l = CheckBal(root->left);
        int r = CheckBal(root->right);
        if(l==-1 || r==-1) return -1;
        if(abs(l-r)>1) return -1;
        return 1+max(l,r);
    }
public:
    bool isBalanced(TreeNode* root) {
        if(root==0)return true;
        if(CheckBal(root)==-1)return false;
        else return true;
        
    }
};