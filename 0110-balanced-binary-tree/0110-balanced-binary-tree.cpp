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
    int dfsHeight(TreeNode *root) {
        if (root == NULL) return 0;

        // Recursively calculate the height of the left subtree
        int leftHeight = dfsHeight(root->left);

        // If the left subtree is unbalanced, propagate the unbalance status
        if (leftHeight == -1) 
            return -1;

        // Recursively calculate the height of the right subtree
        int rightHeight = dfsHeight(root->right);

        // If the right subtree is unbalanced, propagate the unbalance status
        if (rightHeight == -1) 
            return -1;
        if (abs(leftHeight - rightHeight) > 1)  
            return -1;

        // Return the maximum height of left and right subtrees, adding 1 for the current node
        return max(leftHeight, rightHeight) + 1;
    }

    bool isBalanced(TreeNode* root) {
        return dfsHeight(root) != -1;
    }
};