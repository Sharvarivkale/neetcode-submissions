class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n =nums.size();
        vector<int> output(n,1);


       //calculationg the left side products
        int left=1;
        for(int i=0;i<n;i++){
            output[i]=left;
            left=left*nums[i];
        }

        //now calculating the right side products
        int right=1;
        for(int i=n-1;i>=0;i--){
            output[i]=output[i]*right;
            right=right*nums[i];
        }
        return output;
    }
};
