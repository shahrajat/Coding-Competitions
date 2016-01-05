class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        //merge nums2 into nums1
        int last = n+m-1;
        int l1 = m-1;
        int l2 = n-1;
        while(l1>=0 && l2>=0)
        {
            if(nums1[l1] >= nums2[l2])
            {
                nums1[last--] = nums1[l1--];
            }
            else if(nums1[l1] < nums2[l2])
            {
                nums1[last--] = nums2[l2--];
            }
        }
        while(l1>=0)
        {
            nums1[last--] = nums1[l1--];
        }
        while(l2>=0)
        {
            nums1[last--] = nums2[l2--];
        }
    }
};
