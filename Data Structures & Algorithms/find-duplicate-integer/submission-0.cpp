class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow=nums[0];
        int fast=nums[0];


// here we detect the loop
        do{
            slow=nums[slow];
            fast=nums[nums[fast]];

        }while(slow!=fast);

// now we cal the at which point it intesects
     
     slow=nums[0];

     while(slow!=fast){
        slow=nums[slow];
        fast=nums[fast];
     }
     return slow;

        
        
    }
};
