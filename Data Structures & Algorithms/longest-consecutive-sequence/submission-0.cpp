class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        unordered_set<int> st(nums.begin(),nums.end());
        int current=0;
        int count=0;
        int longest=0;

        for(int num:nums){
            if(st.find(num-1)==st.end()){
                current=num;
                count=1;

                while(st.find(current+1)!=st.end()){
                    current++;
                    count++;
                }
            }
             longest=max(count,longest);
        }
        return longest;

        
    }
};
