class Solution {
public:
    vector<int> dp;
    int robbery(vector<int>& nums, int i, vector<int>& dp){
        if(i>nums.size()-1) return 0;
        if(dp[i]!=-1) return dp[i];
        int take = nums[i] + robbery(nums, i+2, dp);
        int skip = robbery(nums, i+1, dp);
        return dp[i] = max(take, skip);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        dp.resize(n, -1);
        
        return robbery(nums, 0, dp);
    }
};