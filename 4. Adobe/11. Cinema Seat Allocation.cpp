// Link : https://leetcode.com/problems/cinema-seat-allocation/description/

class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int,bool> left;
        unordered_map<int,bool> right;
        unordered_map<int,bool> middle;
        int result=2*n;
        for(auto it:reservedSeats){
        if(it[1]==2 || it[1]==3 || it[1]==4 || it[1]==5){
                if(!left[it[0]]){
                    left[it[0]]=true;
                    result-=1;
                }
            }
        if(it[1]==6 || it[1]==7 || it[1]==8 || it[1]==9){
            if(!right[it[0]]){
                right[it[0]]=true;
                result-=1;
            }
        }
        if(it[1]==4 || it[1]==5 || it[1]==6 || it[1]==7){
            middle[it[0]]=true;
        }
        }
        for(auto it:reservedSeats){
            if(!middle[it[0]] && right[it[0]] && left[it[0]]){
                middle[it[0]]=true;
                result+=1;
            }
        }
        return result;


    }
};