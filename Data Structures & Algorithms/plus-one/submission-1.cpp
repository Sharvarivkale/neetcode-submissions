class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
       int carry=1;

       for(int i =digits.size()-1;i>=0;i--){

        if(digits[i]<=9){
            int sum=digits[i]+carry;
            digits[i]=sum%10;
            carry=sum /10;
        }

       }
        if(carry==1){
            digits.insert(digits.begin(),1);
        }
       return digits;
       
        
    }
};
