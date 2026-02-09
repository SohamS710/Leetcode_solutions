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
     void inorder(TreeNode* root, vector<int>& nodes) {
        if (root == NULL) return;
        inorder(root->left, nodes);
        nodes.push_back(root->val);
        inorder(root->right, nodes);
    }

    // Build a height-balanced BST from sorted array
    TreeNode* buildBinarySearchTree(int left, int right, vector<int>& nodes) {
        if (left > right) return NULL;

        int mid = (left + right) / 2; // choose middle element as root
        TreeNode* newNode = new TreeNode(nodes[mid]);

        // Recursively build left and right subtrees
        newNode->left = buildBinarySearchTree(left, mid - 1, nodes);
        newNode->right = buildBinarySearchTree(mid + 1, right, nodes);

        return newNode;
    }
public:
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> nodes;

        // Step 1: Store inorder traversal of BST
        inorder(root, nodes);

        // Step 2: Build balanced BST from sorted values
        return buildBinarySearchTree(0, nodes.size() - 1, nodes);        
    }
};