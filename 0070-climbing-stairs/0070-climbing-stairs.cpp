class Solution {
public:
    vector<int> dp;

    int ways(int n) {
        if (n <= 2)
            return n;

        if (dp[n] != -1)
            return dp[n];

        return dp[n] = ways(n - 1) + ways(n - 2);
    }

    int climbStairs(int n) {
        dp.resize(n + 1, -1);
        return ways(n);
    }
};
