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
    bool isValid(TreeNode* root, long min , long max){
         if(root==NULL) return true;
        if(root->val>=max || root->val <=min ) return false; // root value if less then min and if more than max return false
        return isValid(root->left,min,root->val) && isValid(root->right,root->val,max); // else check for root left with min as min and max as root->val and move right and  min as root->val and max as max
        

    }
public:
    bool isValidBST(TreeNode* root) {
        if(root->left==NULL && root->right==NULL) return true;
       
        return isValid(root , LONG_MIN, LONG_MAX);
        
    }
};