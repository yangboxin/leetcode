class Solution {
public:
    int gcd(int a,int b){
        if(a==0)
            return b;
        return gcd(b%a,a);
    }
    int nthMagicalNumber(int n, int a, int b) {
        int mod=1e9+7;
        int lcm=a*b/gcd(a,b);
        long low=0,high=4e13;
        while(low<high){
            long mid=low+(high-low)/2;
            long idx=(mid/a+mid/b-mid/lcm);
            if(idx<n)
                low=mid+1;
            else
                high=mid;
        }
        return (int)(low%mod);
    }
};
