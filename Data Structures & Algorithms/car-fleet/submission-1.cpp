class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {

        vector<pair<int,int>> cars;
        stack<double>st;

        for(int i=0;i<position.size();i++){
            cars.push_back({position[i],speed[i]});
        }

        sort(cars.begin(),cars.end());

        for(int i=position.size()-1;i>=0;i--){

            int pos=cars[i].first;
            int spd=cars[i].second;
            double time=(double) (target-pos)/spd;

            if(st.empty() || time>st.top()){
                st.push(time);
            }
        }
        return st.size();
        
    }
};
