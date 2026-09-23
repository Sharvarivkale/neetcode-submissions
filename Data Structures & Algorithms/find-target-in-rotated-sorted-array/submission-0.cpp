class Solution {
    int getpivot(vector<int>& nums){
        int s=0;
        int e=nums.size()-1;
        int mid=s+(e-s)/2;
        while(s<e){
            if(nums[mid]>nums[e]){
                s=mid+1;
            }
            else{
                e=mid;
            }
            mid=s+(e-s)/2;
        }
        return s;
    }
    int binarysearch(vector<int>& nums, int target,int s,int e){

        int mid=s+(e-s)/2;
        while(s<=e){
            if(nums[mid]==target){
                return mid;
            }
            else if(nums[mid]<target){
                s=mid+1;
            }
            else{
                e=mid-1;
            }
            mid=s+(e-s)/2;
        }
        return -1;
    }
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int pivot=getpivot(nums);
        if(nums[pivot]<=target  && target<=nums[n-1]){
            return binarysearch(nums,target,pivot,n-1);
        }
        else{
            return binarysearch(nums,target,0,pivot-1);
        }

        
    }
};
