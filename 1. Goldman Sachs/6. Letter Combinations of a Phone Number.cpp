// Link : https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string>result;
        if(digits.empty()) return result;
        vector<string>letter({"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"});
        string path = "";
        DFS(digits, 0, path, result, letter);
        return result;
    }
    
    void DFS(string digits, int pos, string& path, vector<string>& result, vector<string>& letter){
        if(pos == digits.size()){
            result.push_back(path);
            return;
        }
        for(auto c: letter[digits[pos] - '0']){
            path.push_back(c);
            DFS(digits, pos + 1, path, result, letter);
            path.pop_back();
        }
    }
};