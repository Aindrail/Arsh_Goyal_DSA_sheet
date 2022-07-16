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
   bool compareTrees(TreeNode *root, TreeNode *subRoot)  {
        // checking if both nodes are NULL
        return root == subRoot ||
            // or both present and we can recurse
            root && subRoot && root->val == subRoot->val &&
            // checking the left side
            compareTrees(root->left, subRoot->left) &&
            // checking the right side
            compareTrees(root->right, subRoot->right);
    }
public:
    bool isSubtree(TreeNode *root, TreeNode *subRoot) {
        return root ? (
            compareTrees(root, subRoot) || isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot)
        ) : false;
    }
};