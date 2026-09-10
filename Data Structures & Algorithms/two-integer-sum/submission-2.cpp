class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       vector<pair<int,int>>arr;
       int n=nums.size();

        for(int i=0;i<nums.size();i++){
          arr.push_back({nums[i],i});
        }

        sort(arr.begin(),arr.end());

        int i=0;
        int j=n-1;
        int sum=0;
     
       while(i<j){
        int sum=arr[i].first+arr[j].first;
        if(sum==target){
            return{min(arr[i].second,arr[j].second),max(arr[i].second,arr[j].second)};
        }
        else if(sum<target){
            i++;
        }
        else{
            j--;
        }
       }

        
    }
};
