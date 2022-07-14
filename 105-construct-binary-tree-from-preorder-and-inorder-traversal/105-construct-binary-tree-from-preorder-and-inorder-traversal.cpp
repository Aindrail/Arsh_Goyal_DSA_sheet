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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> mp;
        for (int i = 0; i < inorder.size(); ++i) mp[inorder[i]] = i;
        int index = 0;
        return buildTree(mp, 0, preorder.size() - 1, preorder, inorder, index);
    }
    
    TreeNode* buildTree(unordered_map<int, int>& mp, int left, int right, vector<int>& pre, vector<int>& in, int& i) {
        if (left > right) return nullptr;
        
        int rt = pre[i++];
        TreeNode* root = new TreeNode(rt);
        root->left = buildTree(mp, left, mp[rt] - 1, pre, in, i);
        root->right = buildTree(mp, mp[rt] + 1, right, pre, in, i);
        return root;
    }
};