class Solution {
public:
    vector<int> dp;
    int minCost(vector<int>& cost, int n, vector<int>& dp){
        if(n<=1) return cost[n];
        if(dp[n]!=-1) return dp[n];
        return dp[n] = cost[n] + min(minCost(cost, n-1, dp), minCost(cost, n-2, dp));

    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size()-1;
        dp.resize(n+1, -1);
        return min(minCost(cost, n, dp), minCost(cost, n-1, dp));
    }
};