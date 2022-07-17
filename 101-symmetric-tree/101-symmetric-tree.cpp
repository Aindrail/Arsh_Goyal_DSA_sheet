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
    bool isSymmetric(TreeNode* l, TreeNode* r){
        if(l==NULL || r ==NULL){
            return (l==r);
        }
            return (l->val == r->val)&& isSymmetric(l->left,r->right) && isSymmetric(l->right,r->left); // see the example 
    
    }
public:
    bool isSymmetric(TreeNode* root) {
        if(root==NULL||(root->left==NULL && root->right==NULL))return true; // if root is null or both left and right is null
        return isSymmetric(root->left,root->right);
    }
};