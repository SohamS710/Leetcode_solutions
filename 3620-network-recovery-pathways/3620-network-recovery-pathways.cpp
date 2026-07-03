class Solution {
public:
    using ll = long long;
    using P = pair<ll, int>;

    bool check(int mid, int n, ll k, unordered_map<int, vector<vector<int>>> &adj) {

        vector<ll> dist(n, LLONG_MAX);

        priority_queue<P, vector<P>, greater<P>> pq;

        dist[0] = 0;
        pq.push({0, 0});

        while (!pq.empty()) {
            auto [d, node] = pq.top();
            pq.pop();

            if (d > dist[node]) continue;

            if (d > k) break;

            if (node == n - 1) return true;

            for (auto &e : adj[node]) {
                int v = e[0];
                int cost = e[1];

                if (cost < mid) continue;

                if (d + cost < dist[v]) {
                    dist[v] = d + cost;
                    pq.push({dist[v], v});
                }
            }
        }

        return false;
    }

    int findMaxPathScore(vector<vector<int>>& edges,
                         vector<bool>& online,
                         long long k) {

        int n = online.size();

        unordered_map<int, vector<vector<int>>> adj;

        int l = INT_MAX;
        int r = 0;

        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];
            int w = e[2];

            if (!online[u] || !online[v]) continue;

            adj[u].push_back({v, w});

            l = min(l, w);
            r = max(r, w);
        }

        if (l == INT_MAX) return -1;

        int ans = -1;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (check(mid, n, k, adj)) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        return ans;
    }
};