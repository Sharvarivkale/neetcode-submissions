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
    int best = INT_MIN;

    int gain(TreeNode* node) {
        if (!node) return 0;

        int left  = max(0, gain(node->left));
        int right = max(0, gain(node->right));

        // Path that bends at this node
        best = max(best, node->val + left + right);

        // Path that can be extended upward through the parent
        return node->val + max(left, right);
    }

    int maxPathSum(TreeNode* root) {
        best = INT_MIN;
        gain(root);
        return best;
    }
};
