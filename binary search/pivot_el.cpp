class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int start=0;
        int end=n-1;

        while(start<end)
        {
            int mid=(start+end)/2;
            if(nums[mid]>nums[end])
            {
                start=mid+1;
            }
            else
            {
                end=mid;
            }
        }
        return nums[start];
    }
};

// find min in rotated sorted array 
// what we have to do is to compare mid with end 
// why not start because obviously end is better