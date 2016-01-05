/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    //following is O(n)
    bool isBalanced(TreeNode* root) {
        if(height1(root) ==-1)
            return false;
        else 
            return true;
    }
    
    //modify height function to return -1 when current node is not balanced
    int height1(TreeNode *root)
    {
        if(root==NULL)
            return 0;
        int lh = height1(root->left);
        if(lh==-1)
            return -1;
        int rh = height1(root->right);
        if(rh==-1)
            return -1;
        if(abs(lh-rh)>1)
            return -1;
        else
            return 1+max(height1(root->left), height1(root->right));
    }
};
