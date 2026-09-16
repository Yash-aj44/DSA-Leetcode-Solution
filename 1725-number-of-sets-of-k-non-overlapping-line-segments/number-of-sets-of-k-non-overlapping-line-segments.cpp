class Solution {
public:
    int numberOfSets(int n, int k) {
        const int MOD = 1e9 + 7;

        // dp[i] = ways to form current number of segments
        // using points 0...i
        vector<long long> dp(n, 1);

        for (int segments = 1; segments <= k; segments++) {
            vector<long long> next(n, 0);

            // dp[i] from previous iteration represents
            // ways to form segments-1 segments using 0...i

            long long prefix = 0;

            for (int i = 1; i < n; i++) {
                // Add dp[i-1] to the possible starting positions
                prefix = (prefix + dp[i - 1]) % MOD;

                // Option 1:
                // Don't use point i as the endpoint of a new segment
                //
                // Option 2:
                // Create the last segment ending at i
                next[i] = (next[i - 1] + prefix) % MOD;
            }

            dp = next;
        }

        return dp[n - 1];
    }
};
