class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map <int, vector<int>> mp;
        for (vector <int> &edges : edges) {
            int u = edges[0];
            int v = edges[1];

            mp[u].push_back(v);
            mp[v].push_back(u);
        }

        vector <bool> visited(n,false);

        queue<int> que;
        que.push(source);
        visited[source] = true;

        while (!que.empty()) {
            int node = que.front();
            que.pop();

            if (node == destination) return true;

            for (auto &V : mp[node]) {
                if (!visited[V]) {
                    que.push(V);
                    visited[V] = true;
                }
            }
        }
        return false;
    }
};