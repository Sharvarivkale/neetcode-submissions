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

    int height(TreeNode* root, int& diameter) {

        // Base case
        if (root == NULL) {
            return 0;
        }

        // Find height of left subtree
        int left = height(root->left, diameter);

        // Find height of right subtree
        int right = height(root->right, diameter);

        // Check diameter passing through current node
        diameter = max(diameter, left + right);

        // Return height of current node
        return 1 + max(left, right);
    }

    int diameterOfBinaryTree(TreeNode* root) {

        int diameter = 0;

        height(root, diameter);

        return diameter;
    }
};
