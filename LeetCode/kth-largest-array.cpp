class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, std::vector<int>, std::greater<int> > min_heap;
        int len = nums.size();
        for(int i=0; i<k; i++)
            min_heap.push(nums[i]);
        for(int i=k; i<len; i++)
            if(nums[i] > min_heap.top())
            {
                min_heap.pop();
                min_heap.push(nums[i]);
            }
        return min_heap.top();
    }
};
