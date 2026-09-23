class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        //here we use the pair of stack for the temperarture and index
        stack<pair<int,int>>st;
        vector<int> ans(temperatures.size(), 0);

        for(int i=temperatures.size()-1;i>=0;i--){
            //when we got the greater temperature from the current
            while(!st.empty() && st.top().first<=temperatures[i]){
                st.pop();
            }
            //for storing the indexes
            if(!st.empty()){
                ans[i]=st.top().second-i;
            }
            st.push({temperatures[i],i});


        }
        return ans;
        
    }
};
