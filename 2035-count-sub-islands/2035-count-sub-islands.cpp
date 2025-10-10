class Solution {
public:
    int m, n;
    vector<vector<int>>* grid1Ptr;  // Pointer to grid1 for easier access
    vector<vector<int>>* grid2Ptr;  // Pointer to grid2 for DFS marking

    void dfs(int i, int j) {
        // Boundary and base conditions
        if (i < 0 || i >= m || j < 0 || j >= n || (*grid2Ptr)[i][j] == 0)
            return;

        // Mark current cell as visited
        (*grid2Ptr)[i][j] = 0;

        // Visit neighbors (up, down, left, right)
        dfs(i + 1, j);
        dfs(i - 1, j);
        dfs(i, j + 1);
        dfs(i, j - 1);
    }

    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        m = grid1.size();
        n = grid1[0].size();

        grid1Ptr = &grid1;
        grid2Ptr = &grid2;

        // Step 1: Remove parts of grid2 that are land but not land in grid1
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if ((*grid2Ptr)[i][j] == 1 && (*grid1Ptr)[i][j] == 0) {
                    dfs(i, j);  // Erase this island portion in grid2
                }
            }
        }

        int count = 0;

        // Step 2: Count remaining islands in grid2 (these are valid sub-islands)
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if ((*grid2Ptr)[i][j] == 1) {
                    dfs(i, j);
                    count++;
                }
            }
        }

        return count;
    }
};
