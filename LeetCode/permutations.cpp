#include <algorithm>
class Solution {
public:
    //same functionality as next_permutation in C++ algorithms library
    bool mynext_permutation(vector<int>::iterator first, vector<int>::iterator last)
    {
        //last is beyond last element
        auto i = last, j = last;
        if(first==last || first+1 == last) //0 or 1 element vector
            return false;
        i -= 2;
        while(i!=first)
        {
            if(*i < *(i+1))
                break;
            i--;
        }
        j--;
        if(i!=first)
        {
            while(j!=first && *j < *i)
                j--;
            if(j!=first)
            {
                iter_swap(i,j);
                reverse(i,last);
                return true;
            }
        }
        else
        {
            reverse(first,last);
            return false;
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(),nums.end());
        do
        {
            result.push_back(nums);
        }while(mynext_permutation(nums.begin(),nums.end()));
        return result;
    }
};
