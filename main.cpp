class Solution {
public:

    bool inLand(vector<vector<int>>& grid, int x, int y){
        
        return x >= 0 && y >= 0 && x < grid[0].size() && y < grid.size();
    }

    int findLand(vector<vector<int>>& grid, int x, int y){
        if (!inLand(grid, x, y) || grid[y][x] == 0){
            return 0;
        }
        grid[y][x] = 0;
        return 1 + findLand(grid, x + 1, y) + findLand(grid, x - 1, y) + findLand(grid, x, y + 1) + findLand(grid, x, y - 1);
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int y = grid.size();
        int x = grid[0].size();
        int maxArea = 0;

        for (int i = 0; i < y; i++) {
            for (int j = 0; j < x; j++) {
                
                if (grid[i][j] == 1) {
                    maxArea = max(maxArea, findLand(grid, j, i)); 
                }
            }
        }
        return maxArea;
    }
};

