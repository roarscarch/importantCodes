class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;
        stack<int> st;
        for(auto as: asteroids){
            if(st.empty() || as * st.top() > 0){
                st.push(as);// same direction hai push kar do
            }
            else{
                while(!st.empty() && st.top() > 0 && st.top() < abs(as)){
                    st.pop();
                }
                if(st.empty() || st.top() < 0){
                    st.push(as);
                }
                else if(st.top() == abs(as)){// st.top >0
                    st.pop();
                }
            }
        }
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
