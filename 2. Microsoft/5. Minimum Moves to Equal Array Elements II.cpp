// Link : https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/description/

class Solution {
public:
    int find(vector<int>& nums, int avg){
        int result=0;
        for(int x:nums) result+= abs(x-avg);
        
        return result;
    }
    
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        int ln= nums.size();
        
        // find median and try to convert all elements equal to median
        if(ln%2) return find(nums,nums[ln/2]);
        return min(find(nums, nums[ln/2]), find(nums, nums[(ln/2) -1]));
    }
};
