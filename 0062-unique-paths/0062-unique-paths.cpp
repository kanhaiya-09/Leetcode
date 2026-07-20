class Solution {
public:
    int ways(int row, int col, int m, int n, vector<vector<int>>& dp) {
        // Out of bounds
        if (row >= m || col >= n)
            return 0;

        // Destination reached
        if (row == m - 1 && col == n - 1)
            return 1;

        // Already computed
        if (dp[row][col] != -1)
            return dp[row][col];

        int rightWays = ways(row, col + 1, m, n, dp);
        int downWays = ways(row + 1, col, m, n, dp);

        return dp[row][col] = rightWays + downWays;
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return ways(0, 0, m, n, dp);
    }
};