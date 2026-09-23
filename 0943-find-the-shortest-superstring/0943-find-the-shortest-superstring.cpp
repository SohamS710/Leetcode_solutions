class Solution {
public:

    int calc(string a, string b) {
        for (int i = 1; i < a.length(); i++) {
            if (b.find(a.substr(i)) == 0) {
                return b.length() - a.length() + i;
            }
        }
        return b.length();
    }

    string shortestSuperstring(vector<string>& A) {
        int n = A.size();

        // Build overlap graph
        vector<vector<int>> graph(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                graph[i][j] = calc(A[i], A[j]);
            }
        }

        // DP
        int total = 1 << n;

        vector<vector<int>> dp(total, vector<int>(n, INT_MAX));
        vector<vector<int>> path(total, vector<int>(n, -1));

        int last = -1;
        int minLen = INT_MAX;

        // Start TSP DP
        for (int mask = 1; mask < total; mask++) {

            for (int j = 0; j < n; j++) {

                if (mask & (1 << j)) {

                    int prev = mask ^ (1 << j);

                    if (prev == 0) {
                        dp[mask][j] = A[j].length();
                    }
                    else {
                        for (int k = 0; k < n; k++) {

                            if (dp[prev][k] != INT_MAX &&
                                dp[prev][k] + graph[k][j] < dp[mask][j]) {

                                dp[mask][j] =
                                    dp[prev][k] + graph[k][j];

                                path[mask][j] = k;
                            }
                        }
                    }
                }

                // Find minimum for complete mask
                if (mask == total - 1 &&
                    dp[mask][j] < minLen) {

                    minLen = dp[mask][j];
                    last = j;
                }
            }
        }

        // Reconstruct path
        int mask = total - 1;
        vector<int> order;

        while (mask > 0) {
            order.push_back(last);

            int prevLast = path[mask][last];

            mask ^= (1 << last);
            last = prevLast;
        }

        reverse(order.begin(), order.end());

        // Build answer
        string ans = A[order[0]];

        for (int i = 1; i < order.size(); i++) {
            int prev = order[i - 1];
            int curr = order[i];

            int overlapLength =
                A[curr].length() - graph[prev][curr];

            ans += A[curr].substr(overlapLength);
        }

        return ans;
    }
};