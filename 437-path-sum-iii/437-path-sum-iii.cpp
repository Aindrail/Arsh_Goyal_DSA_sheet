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
    long long sums[1001];
    int pos = 0, t, res = 0;
    void dfs(TreeNode *root, bool isLast = true) {
        // support variables
        int val = root->val;
        // checking if val alone matches t
        if (val == t) res++;
        // updating all the prefix sums and then the value itself at the end of it
        for (int i = 0; i < pos; i++) {
            sums[i] += val;
            if (sums[i] == t) res++;
        }
        sums[pos++] = val;
        if (root->left) dfs(root->left, isLast && !root->right);
        if (root->right) dfs(root->right, isLast);
        // backtracking on the prefix sums
        if (!isLast) {
            pos--;
            for (int i = 0; i < pos; i++) sums[i] -= val;
        }
    }
public:
    int pathSum(TreeNode *root, int targetSum) {
        if (!root) return 0;
        t = targetSum;
        dfs(root);
        return res;
    }
};