// Link : https://leetcode.com/problems/k-divisible-elements-subarrays/description/

class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        set<vector<int>>s;
        for(int i = 0; i < nums.size(); i++){
            vector<int> temp;
            int count = 0;
            for(int j = i; j >= 0; j--){
                temp.push_back(nums[j]);
                if(nums[j]%p == 0){
                    count++;
                }
                if(count <= k){
                    s.insert(temp);
                }else{
                    break;
                }
            }
        }
        return s.size();
    }
};

