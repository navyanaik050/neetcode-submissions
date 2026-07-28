class Solution {
    vector<pair<int, int>> directions = {{1,0} , {-1,0}, {0,1}, {0,-1}};
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int rows = heights.size();
        int columns = heights[0].size();
        vector<vector<bool>> pac (rows, vector<bool>(columns, false));
        vector<vector<bool>> atl (rows, vector<bool>(columns, false));

        for(int c=0; c<columns; c++){
            dfs(0, c, pac, heights);
            dfs(rows-1, c, atl, heights);
        }

        for(int r=0; r<rows; r++){
            dfs(r, 0, pac, heights);
            dfs(r, columns-1, atl, heights);
        }

        vector<vector<int>> res;
        for(int row=0; row<rows; row++){
            for(int column=0; column<columns; column++){
                if(pac[row][column] && atl[row][column]){
                    res.push_back({row, column});
                }
            }
        }
        return res;
    }

    void dfs(int row, int column, vector<vector<bool>> &ocean, vector<vector<int>> &heights){
        ocean[row][column] = true;
        for(auto [dr, dc] : directions){
            int nr = row+dr;
            int nc = column+dc;
            if(nr >= 0 && nr < heights.size() &&
               nc >= 0 && nc < heights[0].size() &&
               !ocean[nr][nc] && heights[nr][nc] >= heights[row][column]){
                dfs(nr, nc, ocean, heights);
               }
        }
    }

};
