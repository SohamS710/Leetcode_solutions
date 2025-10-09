class Pair {
public:
    int first;
    int second;

    Pair(int f, int s) {
        first = f;
        second = s;
    }
};

class Solution {
private:
    private:
void bfs(int row, int col, vector<vector<int>>& vis, vector<vector<char>>& grid) {
    vis[row][col] = 1;
    queue<Pair> q;
    q.push(Pair(row, col));

    int n = grid.size();
    int m = grid[0].size();

    int drow[] = {-1, 0, 1, 0};
    int dcol[] = {0, 1, 0, -1};

    while (!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nrow = r + drow[i];
            int ncol = c + dcol[i];

            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                grid[nrow][ncol] == '1' && vis[nrow][ncol] == 0) {
                vis[nrow][ncol] = 1;
                q.push(Pair(nrow, ncol));
            }
        }
    }
}


public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int cnt = 0;

        for (int row = 0; row < n; row++) {
            for (int col = 0; col < m; col++) {
                if (vis[row][col] == 0 && grid[row][col] == '1') {
                    cnt++;
                    bfs(row, col, vis, grid);
                }
            }
        }

        return cnt;
    }
};