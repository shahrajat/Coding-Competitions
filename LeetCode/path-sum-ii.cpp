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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        list<list<int>> res =  pathSum1(root,sum);
        vector<vector<int>> result;
       // std::vector<T> v{ std::begin(l), std::end(l) };
        for(auto r : res)
        {
            vector<int> temp{begin(r),end(r)};
            //reverse(temp.begin(),temp.end());
            result.push_back(temp);
        }
        return result;
    }
    
    list<list<int>> pathSum1(TreeNode* root, int sum) {
        list<list<int>> result;
        if(root)
        {
            if(root->left==NULL && root->right==NULL &&  root->val==sum)   //this is leaf node
            {
                list<int> temp{root->val};
                result.push_back(temp);
            }
            else
            {
                list<list<int>> left = pathSum1(root->left, (sum-root->val));
                list<list<int>> right = pathSum1(root->right, (sum-root->val));
                for(auto itr = left.begin(); itr!=left.end();itr++)
                {
                    (*itr).push_front(root->val);
                    result.push_back(*itr);
                }
                for(auto itr = right.begin(); itr!=right.end();itr++)
                {
                    (*itr).push_front(root->val);
                    result.push_back(*itr);
                }
            }
        }
        return result;
    }
};
