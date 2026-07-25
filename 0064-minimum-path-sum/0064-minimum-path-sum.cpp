class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans[m][n];
        int i, j = 1;
        ans[0][0] = grid[0][0];
        for(int k = 1;k < n;k++){
            ans[0][k] = grid[0][k] + ans[0][k-1];
        }
        for(int k = 1;k < m;k++){
            ans[k][0] = grid[k][0] + ans[k-1][0];
        }
        for(int k =1;k<m;k++){
            for(int p=1; p<n;p++){
                ans[k][p] = min(ans[k-1][p], ans[k][p-1]) + grid[k][p];
            }
        }
        return ans[m-1][n-1];
    }
};