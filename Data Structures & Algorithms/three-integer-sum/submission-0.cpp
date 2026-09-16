class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // apply the 2d vector array
        vector<vector<int>>ans;
        int target =0;

        // first sort the nums array
        sort(nums.begin(),nums.end());
        
        //render the for loop for the uses the nums[i]
        for(int i=0;i<nums.size();i++){
            //initilised
            int left=i+1;
            int right=nums.size()-1;
            
            
            //if i duplicates
            if(i>0 && nums[i]==nums[i-1]){
                continue;
            }

            while(left<right){
                int sum=nums[i]+nums[left]+nums[right];

                if(sum==target){
                    ans.push_back({nums[i],nums[left],nums[right]});
                    left++;
                    right--;
                     //for checking the left duplicates
                while(left<right && nums[left]==nums[left-1]){
                    left++;
                }
                //for checking the right duplicates
                while(left<right && nums[right]==nums[right+1]){
                    right--;
                }
                }
               
                else if(sum<target){
                    left++;
                }
                else{
                    right--;
                }

            }

        }
        return ans;
    }
};
