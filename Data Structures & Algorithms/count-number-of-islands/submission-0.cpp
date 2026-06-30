class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        int columns = grid[0].size();
        int count =0;
        int direction[5] = {-1, 0, 1, 0, -1};

        function <void(int, int)> dfs = [&](int row, int column){
            grid[row][column] = '0';
            for(int k=0; k<4; k++){
                int nextRow = row + direction[k];
                int nextColumn = column + direction[k+1];
                if(nextRow >=0 && nextRow < rows &&
                   nextColumn >=0 && nextColumn < columns &&
                   grid[nextRow][nextColumn] == '1'){
                    
                    dfs(nextRow, nextColumn);
                   }
            }
        };
        
        for(int i=0; i<rows; i++){
            for(int j=0; j<columns; j++){
                if(grid[i][j] == '1'){
                    dfs(i, j);
                    count ++;
                }
            }
        }
        return count;
    }
};
