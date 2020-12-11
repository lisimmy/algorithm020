class Solution 
{
public:
    int isLdCount = 0; // 统计岛屿数量
    int row = 0;  // 行
    int field = 0; // 列

    int numIslands(vector<vector<char>>& grid) 
    {
        row = grid.size() - 1;
        field = grid[0].size() - 1;
        for(int i = 0; i <= row; ++i)
        {
            for(int j = 0; j <= field; ++j)
            {
                if(grid[i][j] == '1')
                {
                    // 遇到1， 岛屿数量+1，递归修改所有与该1相邻的位置为‘0’
                    isLdCount++;
                    dfs(grid, i, j);
                }
            }
        }
        return isLdCount;
    }

    void dfs(vector<vector<char>>& grid, int i, int j)
    {
        // 递归终止， 越界
        if(i < 0 || j < 0 || i > row || j > field)
            return;
        // 递归终止，  碰到了0
        if(grid[i][j] == '0')
            return;
        // 修改当前递归层 ，如果是‘1’，修改为0，不断缩减陆地的思想
        if(grid[i][j] == '1') 
            grid[i][j] = '0';

        // 下探
        dfs(grid, i + 1, j);
        dfs(grid, i, j + 1);
        dfs(grid, i - 1, j);
        dfs(grid, i, j - 1);

    }
};