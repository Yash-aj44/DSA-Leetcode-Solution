class Solution {
public:
    int distinctSubseqII(string s) {
        const int MOD = 1e9 + 7;

        // last[c] = number of distinct subsequences
        // before the previous occurrence of character c
        vector<long long> last(26, 0);

        long long dp = 1; // empty subsequence

        for (char c : s) {
            int idx = c - 'a';

            long long newDp = (2 * dp - last[idx] + MOD) % MOD;

            // Store the old dp for future duplicate removal
            last[idx] = dp;

            dp = newDp;
        }

        // Remove the empty subsequence
        return (dp - 1 + MOD) % MOD;
    }
};