// Link : https://leetcode.com/problems/verify-preorder-serialization-of-a-binary-tree/description/

class Solution {
public:
    bool isValidSerialization(string preorder) {
        stringstream ss(preorder);
        string cur;
        int nodes = 1;
        while (getline(ss, cur, ',')) {
            nodes--;
            if (nodes < 0) return false;
            if (cur != "#") nodes += 2;
        }
        return nodes == 0;
    }
};