// Link : https://leetcode.com/problems/largest-divisible-subset/

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        
        int n=nums.size();
        vector<int> index(n , -1) , dp(n+1 , 1); 
        sort(nums.begin() , nums.end());     
        int max_len=1;    
        int idx=0;       
        for(int i=1;i<n;i++){
            for(int j=i-1;j>=0;j--){
                if(nums[i]%nums[j]==0){
                    if(dp[i]<1+dp[j]) {
                        dp[i]=1+dp[j];
                        index[i]=j;
                        if(max_len<dp[i]){
                            idx=i;
                            max_len=dp[i];
                        }
                    }
                }
            }
        }     
        vector<int> result;   
        int j=idx;
        while(j>=0){
            result.push_back(nums[j]);
            j=index[j];
        }    
        reverse(result.begin() , result.end());
        return result;
    }
};