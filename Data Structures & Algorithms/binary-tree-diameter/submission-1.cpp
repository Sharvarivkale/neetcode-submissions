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
    int height(TreeNode* root,int &ans){
        if(root==NULL){
            return 0;
        }
        //there is 3 types of option through the current depth 
        //2nd through left side
        //3rd through right side 
        int leftheight=height(root->left,ans);//through left side
        int rightheight=height(root->right,ans);//through right side;
        ans=max(ans,leftheight+rightheight);

        return max(leftheight,rightheight)+1;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int ans=0;
        height(root,ans);
        return ans;
        
    }
};
