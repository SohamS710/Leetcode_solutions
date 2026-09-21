class Solution {
public:
    vector<int> shortestAlternatingPaths(
        int n,
        vector<vector<int>>& redEdges,
        vector<vector<int>>& blueEdges) {

        vector<vector<pair<int, int>>> graph(n);

        // 0 = red, 1 = blue
        for (auto e : redEdges)
            graph[e[0]].push_back({e[1], 0});

        for (auto e : blueEdges)
            graph[e[0]].push_back({e[1], 1});

        // dist[node][color]
        // color = color of the edge used to reach node
        vector<vector<int>> dist(n, vector<int>(2, -1));

        queue<pair<int, int>> q;

        // We can start with either color
        q.push({0, 0});
        q.push({0, 1});

        dist[0][0] = 0;
        dist[0][1] = 0;

        while (!q.empty()) {
            auto [u, lastColor] = q.front();
            q.pop();

            for (auto [v, color] : graph[u]) {

                // Must alternate colors
                if (color == lastColor)
                    continue;

                if (dist[v][color] != -1)
                    continue;

                dist[v][color] = dist[u][lastColor] + 1;
                q.push({v, color});
            }
        }

        vector<int> ans(n, -1);

        for (int i = 0; i < n; i++) {
            if (dist[i][0] == -1)
                ans[i] = dist[i][1];
            else if (dist[i][1] == -1)
                ans[i] = dist[i][0];
            else
                ans[i] = min(dist[i][0], dist[i][1]);
        }

        return ans;
    }
};
