class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        // Directions for moving in the grid (right, left, down, up)
        vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        
        vector<vector<int>> island_id(m, vector<int>(n, -1));  // To store the island IDs
        vector<int> island_area;  // To store the area of each island
        int current_id = 0;
        int largest = 0;

        // Traverse the grid to find all islands and calculate their areas
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1 && island_id[i][j] == -1) {  // Unvisited land
                    int area = explore_land(i, j, grid, island_id, current_id);
                    island_area.push_back(area);  // Save the area of the new island
                    largest = max(largest, area);  // Update the largest island area
                    current_id++;  // Increment the island ID for the next island
                }
            }
        }

        // Now, consider merging water cells with adjacent islands to form the largest possible island
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0) {  // Water cell
                    int possible_area = 1;  // Include this water cell itself
                    set<int> adjacent_islands;  // Set to avoid double-counting islands
                    
                    // Check all four directions for adjacent islands
                    for (auto& dir : directions) {
                        int ni = i + dir.first;
                        int nj = j + dir.second;
                        
                        if (ni >= 0 && ni < m && nj >= 0 && nj < n && grid[ni][nj] == -1) {
                            int island_id_here = island_id[ni][nj];  // Get the island ID of the neighboring cell
                            if (adjacent_islands.find(island_id_here) == adjacent_islands.end()) {
                                adjacent_islands.insert(island_id_here);  // Mark this island as already counted
                                possible_area += island_area[island_id_here];  // Add the island's area
                            }
                        }
                    }
                    
                    // Update the largest possible island size
                    largest = max(largest, possible_area);
                }
            }
        }

        return largest;
    }

private:
    // Helper function to explore an island and mark it as visited
    int explore_land(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& island_id, int current_id) {
        int m = grid.size();
        int n = grid[0].size();
        vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        
        queue<pair<int, int>> q;
        q.push({i, j});
        grid[i][j] = -1;  // Mark land as visited
        island_id[i][j] = current_id;  // Assign the current island ID
        int area = 1;

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            
            for (auto& dir : directions) {
                int ni = x + dir.first;
                int nj = y + dir.second;
                
                if (ni >= 0 && ni < m && nj >= 0 && nj < n) {
                    if (grid[ni][nj] == 1) {  // Found land
                        grid[ni][nj] = -1;  // Mark as visited
                        island_id[ni][nj] = current_id;  // Assign the current island ID
                        q.push({ni, nj});
                        area++;
                    }
                }
            }
        }
        return area;
    }
};
