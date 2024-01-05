// Link : https://leetcode.com/problems/number-of-people-aware-of-a-secret/description/

class Solution {
    int mod = 1e9 + 7;
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<long long> dp(n+1,0);
        long long numOfPeopleSharingSecret = 0;
        dp[1] = 1;

        for(int i = 2; i <= n; i++){
            long long numOfNewPeopleSharingSecret = dp[max(0,i-delay)];
            long long numOfPeopleForgettingSecret = dp[max(0,i-forget)];

            numOfPeopleSharingSecret = (numOfPeopleSharingSecret + numOfNewPeopleSharingSecret - numOfPeopleForgettingSecret+mod)%mod;
            dp[i] = numOfPeopleSharingSecret%mod;

        }   

        long long result = 0;   
        for(int i = n - forget + 1; i <= n; i++){
            result = (result + dp[i])%mod;
        }
        return result%mod;
    }
};