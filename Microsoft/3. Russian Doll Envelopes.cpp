// Link : https://leetcode.com/problems/russian-doll-envelopes/description/

class Solution {
public:
    static bool comp(vector<int> &a, vector<int> &b){
        if(a[0]==b[0]){
            return a[1]>b[1];
        }
        return a[0]<b[0];
    }
        
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), comp);
        int i, j, n=envelopes.size();
        vector<int>Lis;
        
        for(i=0; i<n; i++){
            auto it = lower_bound(Lis.begin(), Lis.end(), envelopes[i][1]);
            if(it==Lis.end()){Lis.push_back(envelopes[i][1]);}
            else{
                *it = envelopes[i][1];
            }
        }
        return Lis.size();
    }
};