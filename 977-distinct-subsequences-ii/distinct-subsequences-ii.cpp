class Solution {
public:
    int distinctSubseqII(string s) {
        const int MOD = 1e9 + 7;

        
        vector<long long> last(26, 0);

        long long dp = 1; 

        for (char c : s) {
            int idx = c - 'a';

            long long newDp = (2 * dp - last[idx] + MOD) % MOD;

           
            last[idx] = dp;

            dp = newDp;
        }

        
        return (dp - 1 + MOD) % MOD;
    }
};