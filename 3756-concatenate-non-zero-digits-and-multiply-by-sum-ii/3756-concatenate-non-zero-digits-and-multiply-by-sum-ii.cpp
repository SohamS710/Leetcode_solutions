class Solution {
public:
    typedef long long ll;
    const int M = 1e9 + 7;

    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.length();

        vector<int> nonZeroCount(n, 0);
        vector<ll> numUpto(n, 0);
        vector<ll> digitSum(n, 0);
        vector<ll> pow10(n + 1, 0);

        pow10[0] = 1;
        for (int i = 1; i <= n; i++) {
            pow10[i] = (pow10[i - 1] * 10) % M;
        }

        nonZeroCount[0] = (s[0] != '0') ? 1 : 0;
        for (int i = 1; i < n; i++) {
            int digit = s[i] - '0';
            nonZeroCount[i] = nonZeroCount[i - 1] + (digit != 0);
        }

        numUpto[0] = s[0] - '0';
        for (int i = 1; i < n; i++) {
            int digit = s[i] - '0';
            if (digit != 0) {
                numUpto[i] = (numUpto[i - 1] * 10 + digit) % M;
            } else {
                numUpto[i] = numUpto[i - 1];
            }
        }

        digitSum[0] = s[0] - '0';
        for (int i = 1; i < n; i++) {
            int digit = s[i] - '0';
            digitSum[i] = digitSum[i - 1] + digit;
        }

        int q = queries.size();
        vector<int> result(q);

        for (int i = 0; i < q; i++) {
            int l = queries[i][0];
            int r = queries[i][1];

            ll sum = digitSum[r] - ((l == 0) ? 0 : digitSum[l - 1]);
            ll numBefore = (l == 0) ? 0 : numUpto[l - 1];
            int k = nonZeroCount[r] - ((l == 0) ? 0 : nonZeroCount[l - 1]);

            ll x = (numUpto[r] - (numBefore * pow10[k]) % M + M) % M;

            result[i] = (x * sum) % M;
        }

        return result;
    }
};