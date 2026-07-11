class Solution {
public:
    void addEdge(vector<int> adjList[], int u, int v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    void dfs(vector<int> adjList[], int i, vector<int>& visited, int& node, int& edge) {
        visited[i] = true;
             node++;
              edge += adjList[i].size();
        for(int nbr : adjList[i]) {
            if(!visited[nbr]) {
                dfs(adjList, nbr, visited, node, edge);
            }
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<int> adjList[n + 1];
        for(int i = 0;i < edges.size();i++) {
            addEdge(adjList, edges[i][0], edges[i][1]);
        }
        int count = 0;
        vector<int> visited(n + 1);
        for(int i = 0;i < n;i++) {
            if(!visited[i]) {
                int node = 0;
                int edge = 0;

                dfs(adjList, i, visited, node, edge);

                if(node* (node - 1) == edge) count++;
            }
        }
        return count;
    }
};