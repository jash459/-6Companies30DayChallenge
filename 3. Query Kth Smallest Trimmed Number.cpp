// Link : https://leetcode.com/problems/query-kth-smallest-trimmed-number/description/

#include<bits/stdc++.h>
class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        vector<int> ans;
        for(auto x:queries)
        {
            priority_queue<pair<string,int>> pq;
            for(int i=0;i<nums.size();i++)
            {
                int t=nums[i].length()-x[1];
                string p=nums[i].substr(t,x[1]);
                if(pq.size()<x[0])
                    pq.push({p,i});
                else
                {
                    if(pq.top().first > p)
                    {
                        pq.pop();
                        pq.push({p,i});
                    }
                }
            }
            int value=pq.top().second;
            ans.push_back(value);
        }
        return ans;
    }
};