class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int total_surplus = 0;
        int surplus = 0;
        int start = 0;
        
        for(int i = 0; i < n; i++){
            total_surplus += gas[i] - cost[i];// check karne ke liye ki possible hai ki nai 
            surplus += gas[i] - cost[i];
            if(surplus < 0){
                surplus = 0;
                start = i + 1;// hum har index par cehck kar rahe hain ki kya wo aakri index tk ja sakta hai ya nahi
            }
        }
        return (total_surplus < 0) ? -1 : start;
    }
};