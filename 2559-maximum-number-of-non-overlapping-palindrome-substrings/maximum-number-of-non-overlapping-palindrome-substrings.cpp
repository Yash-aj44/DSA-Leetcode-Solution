class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.size();

        // dp[i] = maximum number of valid palindromes
        // using s[0 ... i-1]
        vector<int> dp(n + 1, 0);

        // Process every possible center
        for (int center = 0; center < n; center++) {

            // -------------------------
            // Odd length palindromes
            // -------------------------
            int l = center;
            int r = center;

            while (l >= 0 && r < n && s[l] == s[r]) {

                if (r - l + 1 >= k) {
                    dp[r + 1] = max(dp[r + 1], dp[l] + 1);
                }

                l--;
                r++;
            }

            // -------------------------
            // Even length palindromes
            // -------------------------
            l = center - 1;
            r = center;

            while (l >= 0 && r < n && s[l] == s[r]) {

                if (r - l + 1 >= k) {
                    dp[r + 1] = max(dp[r + 1], dp[l] + 1);
                }

                l--;
                r++;
            }

            // We can always ignore s[center]
            // and keep the previous answer.
            dp[center + 1] = max(dp[center + 1], dp[center]);
        }

        return dp[n];
    }
};