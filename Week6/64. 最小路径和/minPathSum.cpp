class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int row = grid.size();
        if(row == 0) return 0;
        int field = grid[0].size();
        if(field == 0) return 0;

        vector<vector<long>> dp(row + 1, vector<long>(field + 1, INT_MAX));
        for(int i = 1; i <= row; ++i) {
            for(int j = 1; j <= field; ++j) {
                if(i == 1 && j == 1) dp[i][j] = grid[i - 1][j - 1];
                else
                    dp[i][j] = grid[i - 1][j - 1] + min(dp[i][j - 1], dp[i - 1][j]);
            }
        }
        return dp[row][field];

    }
};
/*
[[1,3,1],[1,5,1],[4,2,1]]
[[1,2,3],[4,5,6]]
[[1,2,3]]
[[1],[1],[3]]
[]
[[]]
*/