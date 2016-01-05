class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l=0,h=nums.size()-1,m;
        while(l<=h)
        {
            m = l+(h-l)/2;
            if(nums[m]==target)
                return m;
            else if(nums[l] <= nums[m])    //left subarray is sorted
            {
                if(target <= nums[m] && target >= nums[l])        //target lies in left range
                    h = m-1;
                else
                    l = m+1;
            }
            else        //right subarray must be sorted
            {
                if(target >= nums[m] && target <= nums[h])        //target lies in right range
                    l = m+1;
                else
                    h = m-1;
            }
        }
        return -1;
    }
};
