class Solution {
public:
    struct Pair {
        int row, col, time;
        Pair(int r, int c, int t) : row(r), col(c), time(t) {}
    };
    
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<Pair> q;

        int cntFresh = 0;

        // Step 1: Add all rotten oranges to queue and mark them visited
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 2) {
                    q.push(Pair(i, j, 0));
                    vis[i][j] = 2;
                } else {
                    vis[i][j] = 0;
                }
                if (grid[i][j] == 1) cntFresh++;
            }
        }

        int tm = 0;
        int cnt = 0;

        // Directions: up, right, down, left
        int drow[] = {-1, 0, +1, 0};
        int dcol[] = {0, +1, 0, -1};

        while (!q.empty()) {
            int r = q.front().row;
            int c = q.front().col;
            int t = q.front().time;
            q.pop();
            tm = max(tm, t);

            for (int i = 0; i < 4; ++i) {
                int nrow = r + drow[i];
                int ncol = c + dcol[i];

                // Valid fresh orange
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && 
                    vis[nrow][ncol] == 0 && grid[nrow][ncol] == 1) {
                    
                    q.push(Pair(nrow, ncol, t + 1));
                    vis[nrow][ncol] = 2;
                    cnt++;
                }
            }
        }

        if (cnt != cntFresh) return -1;
        return tm;
    }
};
