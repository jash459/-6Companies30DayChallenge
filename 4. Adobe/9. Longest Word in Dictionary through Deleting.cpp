// Link : https://leetcode.com/problems/longest-word-in-dictionary-through-deleting/description/

class Solution {
public:
      bool isSubsequence(string sub, string super){
        int i = 0, j = 0;
        while(i < sub.size() && j < super.size()){
            if(sub[i] == super[j]){
                i++;
                j++;
            }else{
                j++;
            }
        }
        return i == sub.size();
    };
    
    string findLongestWord(string s, vector<string>& d) {
        string result = "";
        for(string& word : d){
            if(word.size() > result.size() || (word.size() == result.size() && word < result)){
                if(isSubsequence(word, s)){
                    result = word;
                }
            }
        }
        return result;
    }
};