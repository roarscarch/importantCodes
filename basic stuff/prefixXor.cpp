class Solution {
public:
    long long beautifulSubarrays(vector<int>& nums) {
        int givenXor=0;
        unordered_map<int,int>mp;
        int n=nums.size();
        int prefiXor=0;
        long long int count=0;
        mp[0]=1;// for the case given xor== prefix xor
        // so prefixXor^givenXor=0
        // so mp[0]=1 pehle se kar diye taaki baad mein if else na karna pade
        for(int i=0;i<n;i++)
        {
            prefiXor=prefiXor^nums[i];
           
           {
              int find=prefiXor^givenXor;
              if( mp[find])
              count+=mp[find];

              mp[prefiXor]++;// prefixor ko store kar diye
           }
        }
        return count;
    }
};