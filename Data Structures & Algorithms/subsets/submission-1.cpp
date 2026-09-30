class Solution {
    void solve(vector<int>& nums,vector<int> output,int index,vector<vector<int>> &ans){
        //here we pass the ans array through the refrence to store in original 
        

        //base condition
        if(index>=nums.size()){
            ans.push_back(output);
            return ;
        }

        //there are 2 conditions to exclude and include

        //exclude
        solve(nums,output,index+1,ans);

        //include
        //first store the index number
        int ele=nums[index];
        //store to output array
        output.push_back(ele);
        //now call include function
        solve(nums,output,index+1,ans);
        output.pop_back();
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        //2d array for the save the sets 
        vector<vector<int>> ans;
        //1d for the output save
        vector<int> output;
        //now index for tracking
        int index=0;
        //recursion call through the function
        solve(nums,output,index,ans);

        return ans;
        
    }
};
