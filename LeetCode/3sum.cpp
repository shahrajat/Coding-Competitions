class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
      vector<vector<int>> ans;
      if(nums.size()<3)
        return ans;
      sort(nums.begin(),nums.end());
      
      for(int i=0;i<nums.size()-2;i++)
      {
          int c = -nums[i];
          int lo=i+1,hi=nums.size()-1;
          if(i>0 && nums[i]==nums[i-1])
            continue;
          while(lo<hi)
          {
              if(nums[lo] + nums[hi] < c)
                lo++;
            else if(nums[lo] + nums[hi] > c)
                hi--;
                else
                {
                    vector<int> temp{nums[i],nums[lo],nums[hi]} ; 
                    ans.push_back(temp);
                    while(lo<hi && nums[lo]==nums[lo+1]) lo++;  //skip same values
                    while(lo<hi && nums[hi]==nums[hi-1]) hi--;  //skip same values
                    lo++;
                    hi--;
                }
          }
      }
      return ans;
    }
};
