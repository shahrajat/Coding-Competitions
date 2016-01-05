class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int len = nums.size();
        if(len > 1 )    // > 1 element in vector
        {
            int i=len-2;
            while(i>=0 && !(nums[i] < nums[i+1]) )
                i--;
            if(i<0)
                reverse(nums.begin(),nums.end());
            else
            {
                int j = len-1;
                while(j>i && nums[j] <= nums[i])
                    j--;
                swap(nums[i],nums[j]);
                reverse(nums.begin()+i+1, nums.end());
            }
        }
    }
};
