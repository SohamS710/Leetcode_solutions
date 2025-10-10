class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        // Create adjacency list (using multiset to keep destinations sorted automatically)
        unordered_map<string, multiset<string>> adj;
        
        // Build the adjacency list from the tickets
        for (auto& t : tickets) {
            adj[t[0]].insert(t[1]);
        }
        
        vector<string> res;
        dfs("JFK", adj, res);  // Start DFS from "JFK"
        
        // The itinerary is constructed in reverse order, so reverse it before returning
        reverse(res.begin(), res.end());
        
        return res;
    }

private:
    void dfs(const string& src, unordered_map<string, multiset<string>>& adj, vector<string>& res) {
        // While there are destinations from the current source
        while (!adj[src].empty()) {
            // Get the lexicographically smallest destination
            string next = *adj[src].begin();
            adj[src].erase(adj[src].begin());  // Remove the used destination

            // Recursively call DFS on the next destination
            dfs(next, adj, res);
        }

        // Add the current source to the result (the airport visited last)
        res.push_back(src);
    }
};
