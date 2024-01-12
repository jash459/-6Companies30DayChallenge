class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int,int> result;
        for(int i:nums)
            result[i]++;
        int ans=0;
        for(auto x:result)
        {
            if(k==0)
            {    
                if(x.second>1)
                ans++;
            }
             else if(result.find(x.first+k)!=result.end())
                ans++;
        }
        
        return ans;
    }
};