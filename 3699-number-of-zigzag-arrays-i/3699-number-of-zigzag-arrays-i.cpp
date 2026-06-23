class Solution {
public:
    int MOD = 1e9 + 7;
    typedef long long ll;

    int zigZagArrays(int n, int l, int r) {
        int N = n;
        int M = r - l + 1;

        ll t[2001][2001][2];   // DP array


        // Base Case
        for (int prevVal = 1; prevVal <= M; prevVal++) {
            t[N][prevVal][0] = 1;
            t[N][prevVal][1] = 1;
        }

        for (int i = N - 1; i >= 0; i--) {   // O(N * M)

            vector<ll> cumSum1(M + 1, 0);
            vector<ll> cumSum0(M + 1, 0);

            for (int val = 1; val <= M; val++) {
                cumSum0[val] = (cumSum0[val - 1] + t[i + 1][val][0]) % MOD;
                cumSum1[val] = (cumSum1[val - 1] + t[i + 1][val][1]) % MOD;
            }

            for (int prevVal = 1; prevVal <= M; prevVal++) {

                t[i][prevVal][1] =
                    (cumSum0[M] - cumSum0[prevVal] + MOD) % MOD;

                t[i][prevVal][0] =
                    cumSum1[prevVal - 1];
            }
        }

        ll result = 0;

        for (int startVal = 1; startVal <= M; startVal++) {
            result = (result + t[1][startVal][1]) % MOD;
            result = (result + t[1][startVal][0]) % MOD;
        }

        return result;
    }
};