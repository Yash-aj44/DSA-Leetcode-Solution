class Solution {
public:
    long long stoneGameVIII(vector<int>& stones) {
        int n = stones.size();

        vector<long long> prefix(n + 1, 0);

        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + stones[i];
        }

        long long dp = prefix[n];

        for (int i = n - 2; i >= 1; i--) {
            dp = max(dp, prefix[i + 1] - dp);
        }

        return dp;
    }
};