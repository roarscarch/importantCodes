class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int right=n-1;
        int left=0;
        int index=0;
        // FFFFFFTTTTTTT
        while(left<right)
        {
            int mid=(left+right)/2;
            if(nums[mid]>=target)//>=target==true
            {
                right=mid;
            }
            else
            {
                left=mid+1;// we want the first true
            }
        }
        if(nums[left]==target)
        return left;
        else
        return -1;
    }
};
// humesha do condition mein tod ho 
// hmko ye bola ki target search karo hum isko bole ki
// less than target ko hum false bolenge and greater than target ko true
// now we have to find our first true in the combination FFFFFFTTTTTT