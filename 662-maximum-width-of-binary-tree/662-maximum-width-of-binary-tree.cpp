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
    int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL) return 0;
        int ans = 0;
        queue<pair<TreeNode*,long>> level;
        level.push({root,0});
        while(!level.empty()){
            int size = level.size();
            int m = level.front().second;
            int first, last;
            for( int i =0 ; i<size; i++){
                long currId = level.front().second-m;
                TreeNode* cur = level.front().first;
                level.pop();
                if(i==0) first = currId;
                if(i==size-1) last = currId;
                if(cur->left){
                  level.push({cur->left,currId*2+1});
                }
                if(cur->right){
                  level.push({cur->right,currId*2+2});
                }
                
                
            }
            ans = max(ans,last-first+1);


        }
        return ans;
        
    }
};