class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int set_size = nums.size();
        long long int num_subsets = pow(2,set_size);
        vector<vector<int>> subsets;
        for(int i=0;i<num_subsets;i++)
        {
            subsets.push_back(vector<int>());
            for(int j=0; j<set_size;j++)
            {
                if(i&(1<<j))
                    subsets[i].push_back(nums[j]);
            }
            sort(subsets[i].begin(),subsets[i].end());
        }
        return subsets;
    }
};
