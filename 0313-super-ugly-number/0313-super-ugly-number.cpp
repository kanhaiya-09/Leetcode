class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<long long> dp(n, 1);
        int k = primes.size();

        vector<int> idx(k, 0);
        vector<long long> val(k);

        for (int j = 0; j < k; j++) {
            val[j] = primes[j];
        }

        for (int i = 1; i < n; i++) {
            long long next = LLONG_MAX;

            for (int j = 0; j < k; j++) {
                next = min(next, val[j]);
            }

            dp[i] = next;

            for (int j = 0; j < k; j++) {
                if (val[j] == next) {
                    idx[j]++;
                    val[j] = dp[idx[j]] * primes[j];
                }
            }
        }

        return dp[n - 1];
    }
};