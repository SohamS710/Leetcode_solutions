class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int cntfresh = 0;
        queue<pair<pair<int,int>, int>> que;

        // Count fresh oranges and push rotten oranges into the queue
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    que.push({{i, j}, 0});
                } else if (grid[i][j] == 1) {
                    cntfresh++;
                }
            }
        }

        int time = 0;
        int rottenCount = 0;
        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};

        // BFS to rot adjacent fresh oranges
        while (!que.empty()) {
            int row = que.front().first.first;
            int col = que.front().first.second;
            int t = que.front().second;
            que.pop();

            time = max(time, t);

            for (int i = 0; i < 4; i++) {
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];

                if (nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && grid[nrow][ncol] == 1) {
                    grid[nrow][ncol] = 2; // Mark orange as rotten
                    que.push({{nrow, ncol}, t + 1});
                    rottenCount++;       // One more fresh orange rotten
                }
            }
        }

        // If all fresh oranges are rotten, return time; otherwise -1
        return (rottenCount == cntfresh) ? time : -1;
    }
};