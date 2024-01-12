// Link : https://leetcode.com/problems/minimize-the-maximum-of-two-arrays/

#include<bits/stdc++.h>
#define ll long long
class Solution {
    ll get_GCD(int a,int b){
        if(b==0)return a;

        return get_GCD(b,a%b);
    }
public:
    int minimizeSet(int div1, int div2, int cnt1, int cnt2) {
        ll ans=INT_MAX;
        ll low=1,high=INT_MAX;
        
        // Iterate with binary search to get Solution.
        while(low<=high){
            ll mid=(low+high)/2;
            // Remaining Numbers Divisible by div1 from total mid numbers
            ll total1=mid-mid/div1;
            // Remaining Numbers Divisible by div2 from total mid numbers
            ll total2=mid-mid/div2;

            // GCD of both div1 and div2
            ll gcd=get_GCD(div1,div2);
            // Get the LCM of 2 numbers
            ll lcm=(ll)(((ll)div1)*((ll)div2))/gcd;

            // Remaining numbers that are not divisible by div1 and div2 from total mid numbers.
            ll temp=mid-mid/lcm;

            // If we have all satisfied then 
            // set the high value to left of mid and store the mid val as ans.
            if(total1>=cnt1 and total2>=cnt2 and temp>=cnt1+cnt2){
                high=mid-1;
                ans=min(ans,mid);
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }

};