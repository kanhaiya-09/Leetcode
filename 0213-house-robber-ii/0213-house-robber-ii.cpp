class Solution {
public:
    vector<int> dp;
    // Tabulation
    int robbery(vector<int>& nums, int start, int end, vector<int>& dp){
        if (start == end)
        return nums[start];
        dp[start] = nums[start];
        dp[start+1] = max(nums[start+1], nums[start]);

        for(int i = start+2;i<=end;i++ ){
            dp[i] = max(nums[i]+dp[i-2], dp[i-1]);
        }
        return dp[end];
    }
    int rob(vector<int>& nums) {
         
        int n = nums.size();
        dp.resize(n);
         if (n == 1)
            return nums[0];
        return max(robbery(nums, 0, n-2, dp), robbery(nums, 1, n-1, dp)); 
    }
};