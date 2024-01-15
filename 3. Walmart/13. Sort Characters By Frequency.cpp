// Link : https://leetcode.com/problems/sort-characters-by-frequency/description/

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> mpp;
        for(char _s: s) mpp[_s]++;
        vector<pair<int,char>> v;
        for(auto _m: mpp) v.push_back({_m.second,_m.first});
        sort(rbegin(v),rend(v));
        s.clear();
        for(auto _v: v) s += string(_v.first,_v.second);
        return s;
    }
};