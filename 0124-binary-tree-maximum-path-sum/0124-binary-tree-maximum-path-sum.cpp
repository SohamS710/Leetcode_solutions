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
    int maxi; // to store the global maximum path sum

    int solve(TreeNode* node) {
        if (node == nullptr) return 0;

        // compute left and right sums, ignoring negatives
        int leftSum = max(0, solve(node->left));
        int rightSum = max(0, solve(node->right));

        // update the global maximum path sum through this node
        maxi = max(maxi, leftSum + rightSum + node->val);

        // return the max gain including this node and one of its subtrees
        return node->val + max(leftSum, rightSum);
    }

    int maxPathSum(TreeNode* root) {
        maxi = INT_MIN;
        solve(root);
        return maxi;
    }
};
