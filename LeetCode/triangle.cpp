class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int rows = triangle.size();
        //go bottom to top and update cell[i][j] with cell[i][j]+min(cell[i+1][j], cell[i+1][j+1])
        for(int r = rows-2; r>=0; r--)
        {
            //update each cell in current row
            for(int c=0; c<triangle[r].size(); c++)
            {
                triangle[r][c] += min(triangle[r+1][c], triangle[r+1][c+1]); 
            }
        }
        return triangle[0][0];
    }
};
