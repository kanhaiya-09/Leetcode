class Solution {
public:
    int n, m;
    vector<vector<vector<int>>> dp;

    bool solve(int i, int j, int balance, vector<vector<char>>& grid) {
        // Invalid balance
        if (balance < 0) return false;

        // Remaining cells cannot close enough parentheses
        int remaining = (n - 1 - i) + (m - 1 - j);
        if (balance > remaining) return false;

        // Destination
        if (i == n - 1 && j == m - 1) {
            return balance == 0;
        }

        if (dp[i][j][balance] != -1)
            return dp[i][j][balance];

        // Move down
        if (i + 1 < n) {
            int newBalance = balance + 
                (grid[i + 1][j] == '(' ? 1 : -1);

            if (solve(i + 1, j, newBalance, grid))
                return dp[i][j][balance] = true;
        }

        // Move right
        if (j + 1 < m) {
            int newBalance = balance + 
                (grid[i][j + 1] == '(' ? 1 : -1);

            if (solve(i, j + 1, newBalance, grid))
                return dp[i][j][balance] = true;
        }

        return dp[i][j][balance] = false;
    }

    bool hasValidPath(vector<vector<char>>& grid) {
        n = grid.size();
        m = grid[0].size();

        // Path length must be even
        if ((n + m - 1) % 2 != 0)
            return false;

        // Must start with '(' and end with ')'
        if (grid[0][0] != '(' || grid[n - 1][m - 1] != ')')
            return false;

        dp.assign(n, vector<vector<int>>(
            m, vector<int>(n + m, -1)
        ));

        int balance = 1; // first cell is '('

        return solve(0, 0, balance, grid);
    }
};