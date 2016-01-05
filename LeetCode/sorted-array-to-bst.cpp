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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return sortedArrayToBST1(nums,0,nums.size()-1);
    }
    TreeNode* sortedArrayToBST1(vector<int>& nums, int l, int r)
    {
        if(l>r)
            return NULL;
        int mid = (l+r)/2;
        TreeNode* n = new TreeNode(nums[mid]);
        n->left = sortedArrayToBST1(nums,l, mid-1);
        n->right = sortedArrayToBST1(nums,mid+1, r);
        return n;
    }
};
