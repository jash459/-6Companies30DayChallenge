// Link : https://leetcode.com/problems/minimum-non-zero-product-of-the-array-elements/description/

class Solution {
public:
    const long long mod=1e9+7;
    long long power(long long x, long long y)
    {
        long long result = 1; 
        while (y > 0) {    
            if (y & 1)
                result =((result%mod) * (x%mod))%mod;
            
            y = y >> 1; 
            x =((x%mod)* (x)%mod)%mod; 
        }
        return result;
    }
    int minNonZeroProduct(int p) {
        long long maxVal=0;
        maxVal=(((long long )1) << p) - 1;
        long long secMax=maxVal-1;
        secMax=secMax%mod;
        long long c=maxVal/2;
        secMax=power(secMax,c);
        maxVal=((maxVal%mod)*(secMax%mod)%mod);
        return (maxVal%mod);
    }
};