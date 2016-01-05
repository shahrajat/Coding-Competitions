class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        for(int r = rows-1; r>=0; r--)
        {
            for(int c = cols-1; c>=0; c--)
            {
                //can go right only
                if(r+1 > rows-1 && c+1 < cols)
                {
                    grid[r][c] += grid[r][c+1];
                }
                else if(c+1 > cols-1 && r+1 < rows) //only down
                {
                    grid[r][c] += grid[r+1][c];
                }
                else if(r+1 < rows && c+1 < cols)   //both option
                {
                    grid[r][c] += min(grid[r][c+1],grid[r+1][c]);
                }
            }
        }
        
        return grid[0][0];
    }
};
