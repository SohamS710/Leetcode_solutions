class Solution {
public:
    vector<vector<int>> directions = {{0,1},{0,-1},{1,0},{-1,0}};

    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> result(m, vector<int>(n, INT_MAX));

        deque<pair<int,int>> deq;

        result[0][0] = grid[0][0];
        deq.push_front({0,0});

        while (!deq.empty()) {
            auto [r,c] = deq.front();
            deq.pop_front();

            for (auto &dir : directions) {
                int nr = r + dir[0];
                int nc = c + dir[1];

                if (nr < 0 || nr >= m || nc < 0 || nc >= n)
                    continue;

                if (result[r][c] + grid[nr][nc] < result[nr][nc]) {
                    result[nr][nc] = result[r][c] + grid[nr][nc];

                    if (grid[nr][nc] == 0)
                        deq.push_front({nr,nc});
                    else
                        deq.push_back({nr,nc});
                }
            }
        }

        return health - result[m-1][n-1] >= 1;
    }
};