class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int m = word1.size();
        int n = word2.size();
        
        int w1i = 0, w2i = 0, i = 0, j = 0; // Indices for words and characters

        // Traverse through both word1 and word2
        while (w1i < m && w2i < n) {
            // Compare characters at word1[w1i][i] and word2[w2i][j]
            if (word1[w1i][i] != word2[w2i][j]) {
                return false;
            }

            i++; // Move to next character in word1
            j++; // Move to next character in word2

            // If we reach the end of word1[w1i], move to the next word
            if (i == word1[w1i].size()) {
                i = 0;
                w1i++;
            }

            // If we reach the end of word2[w2i], move to the next word
            if (j == word2[w2i].size()) {
                j = 0;
                w2i++;
            }
        }

        // If we have completely traversed both arrays and the indices are equal
        return w1i == m && w2i == n;
    }
};
