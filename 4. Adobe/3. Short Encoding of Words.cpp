// Link : https://leetcode.com/problems/short-encoding-of-words/description/

class Solution {
public:
  static bool compare (string& first, string& second) {
        return first.size() > second.size();
    }
    int minimumLengthEncoding(vector<string>& words) {
        unordered_map<string, int> mpp;
        int result = 0;
        sort(words.begin(), words.end(), compare);
        for(int i=0; i<words.size(); i++){
            mpp[words[i]]++;
        }
        for(int i=0; i<words.size(); i++){
            int k = words[i].size();
            if(mpp[words[i]] >0){
                result += (k+1);
            }
        for(int j=k-1; j>=0; j--){
                string s = words[i].substr(j, k-j);
                mpp[s] = 0;
            }
        }
        return result;
    }
};