class Solution {
    public:
    double power(double x, int n){
        if (n==0){
            return 1;
        }
        if(n==1){
            return x;
        }
        double ans=power(x,n/2);

        if(n%2==0){
            return ans*ans;
        }
        else{
            return x*ans*ans;
        }
    }

    double myPow(double x, int n) {
        long long N = n;

        if (N < 0) {
            return 1 / power(x, -N);
        }
        return power(x,  n);
        
        
    }
};
