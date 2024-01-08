// Link : https://leetcode.com/problems/count-number-of-nice-subarrays/description/

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int j = 0, odd = 0, sum = 0, total = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] & 1) {
                odd++;
                if (odd >= k) {
                    sum = 1;
                    while (!(nums[j++] & 1)) sum++;
                    total += sum;
                }
            } else if (odd >= k) total += sum;
        }
        return total;
    }
};

