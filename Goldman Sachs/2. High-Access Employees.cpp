// Link : https://leetcode.com/problems/high-access-employees/description/

#include<bits/stdc++.h>
class Solution {
public:
    vector<string> findHighAccessEmployees(vector<vector<string>>& access_times) {
        unordered_map<string, vector<int>> mpp;
        for (auto& it : access_times) {
            int time = stoi(it[1]);
            mpp[it[0]].push_back(time);
        }
        for (auto& it : mpp) {
            sort(it.second.begin(), it.second.end());
        }
        vector<string> result;
        for (auto& it : mpp) {
            vector<int>& times = it.second;
            for (int i = 2; i < times.size(); i++) {
                if (times[i] - times[i - 2] < 100) {
                    result.push_back(it.first);
                    break;
                }
            }
        }
        return result;
    }
};