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
    int height(TreeNode* root, int &maxD){
        if(root==NULL)return 0;
        int l = height(root->left,maxD);
        int r = height(root->right,maxD);
        maxD = max(maxD,l+r);
        return 1+max(l,r);
        
        
    }
public:
    
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL)return 0;
        int D=0;
        height(root,D);
        return D;
    }
};