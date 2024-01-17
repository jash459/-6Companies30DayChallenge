// Link : https://leetcode.com/problems/trim-a-binary-search-tree/description/

class Solution {
public:
    int longestString(int x, int y, int z) {
        if(x==y)
        {
            return (2*z) + (x * 2)*2;
        }
        return (2*z)+ (min(x,y)*2)*2+2;
    }
};