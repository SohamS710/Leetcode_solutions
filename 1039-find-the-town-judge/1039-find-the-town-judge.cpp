class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if (n == 1 && trust.empty()) {
            return 1; 
        }
        
        vector<int> inDegree(n + 1, 0);
        vector<int> outDegree(n + 1, 0);

        for (auto& t : trust) {
            int a = t[0];
            int b = t[1];
            outDegree[a]++;
            inDegree[b]++;
        }

        for (int person = 1; person <= n; person++) {
            if (inDegree[person] == n - 1 && outDegree[person] == 0) {
                return person;
            }
        }

        return -1;  // No judge found
    }
};
