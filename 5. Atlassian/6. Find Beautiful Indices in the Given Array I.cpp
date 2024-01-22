// Link : https://leetcode.com/problems/find-beautiful-indices-in-the-given-array-i/description/

class Solution {
public:
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        vector<int> c, d;
        int j = 0, n = s.size();
        for(int i=0;i<n;i++) {
            if(s[i] == a[j] and j < a.size()) {
                j++;
            } else {
                if(j == a.size()) c.push_back(i-j);
                j = 0;
                if(s[i] == a[j]) j++;
            }
        }
        if(j == a.size()) c.push_back(n-j);
        j = 0;
        for(int i=0;i<n;i++) {
            if(s[i] == b[j] and j < b.size()) {
                j++;
            } else {
                if(j == b.size()) d.push_back(i-j);
                j = 0;
                if(s[i] == b[j]) j++;
            }
        }
        if(j == b.size()) d.push_back(n-j);
        
        vector<int> ans;
        for(int num1 : c) {
            for(int num2 : d) {
                if(abs(num1-num2) <= k) {
                    ans.push_back(num1);
                    break;
                }
            }
        }
        return ans;
    }
};