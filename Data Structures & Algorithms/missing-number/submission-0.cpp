class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int actual_sum=n*(n+1)/2;
        int here_sum=0;
        int missing_num=0;

        for(int i=0;i<n;i++){
            here_sum += nums[i];
        }

         missing_num=actual_sum-here_sum;
      return missing_num;  
    }
    
};
