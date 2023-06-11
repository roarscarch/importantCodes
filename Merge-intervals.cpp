class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>ans;
        ans.push_back(intervals[0]);
        // pehla wala to jayega hi jayega
        // isme values update kar rahe hain

        for(int i=1;i<intervals.size();i++)
        {
            if(ans.back()[1]>=intervals[i][0])
            {
                ans.back()[1]=max(ans.back()[1],intervals[i][1]);
                // ye step sabkoi galat karta hai tum mat karna
            }
            else
            {
                ans.push_back(intervals[i]);
            }
        }


        return ans;

    }
};