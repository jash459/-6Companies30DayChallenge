// Link : https://leetcode.com/problems/throne-inheritance/description/

class ThroneInheritance {
public:
    unordered_map<string, vector<string>> map;
    unordered_set<string> dead;
    string name_of_king;
    
    ThroneInheritance(string kingName) {
        name_of_king= kingName;
    }
    
    void birth(string par, string child) {
        map[par].push_back(child);
    }
    
    void death(string name) {
        dead.insert(name);
    }
    
    
    void helper(string par, vector<string> &ans){
        if(dead.count(par)==0) ans.push_back(par);
        for(auto child:map[par]) helper(child, ans);
    }
    
    vector<string> getInheritanceOrder() {
        vector<string> ans;
        helper(name_of_king, ans);
        return ans;
    }
};