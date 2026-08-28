class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {

        int n = s.size();
        int half = n / 2;

        // Count characters in s
        vector<int> freq(26, 0);

        for (char c : s) {
            freq[c - 'a']++;
        }

        // Check whether palindrome is possible
        int odd = 0;
        char middle = 0;

        for (int i = 0; i < 26; i++) {
            if (freq[i] % 2 == 1) {
                odd++;
                middle = 'a' + i;
            }
        }

        if (odd > 1) {
            return "";
        }

        // Characters available in the first half
        vector<int> halfFreq(26);

        for (int i = 0; i < 26; i++) {
            halfFreq[i] = freq[i] / 2;
        }

        string prefix = target.substr(0, half);

        // ------------------------------------------------
        // CASE 1:
        // target's first half itself can be constructed
        // ------------------------------------------------

        vector<int> temp = halfFreq;
        bool possible = true;

        for (char c : prefix) {

            if (temp[c - 'a'] == 0) {
                possible = false;
                break;
            }

            temp[c - 'a']--;
        }

        // If prefix is possible, construct the palindrome
        // and check whether it is already greater than target.
        if (possible) {

            string ans = prefix;

            if (n % 2 == 1) {
                ans += middle;
            }

            string rev = prefix;
            reverse(rev.begin(), rev.end());

            ans += rev;

            if (ans > target) {
                return ans;
            }
        }

        // ------------------------------------------------
        // CASE 2:
        // Find the smallest first half strictly greater
        // than target's first half.
        // ------------------------------------------------

        for (int i = half - 1; i >= 0; i--) {

            // Check whether target[0 ... i-1]
            // can be formed from our available characters.
            vector<int> cnt = halfFreq;

            bool validPrefix = true;

            for (int j = 0; j < i; j++) {

                int x = prefix[j] - 'a';

                if (cnt[x] == 0) {
                    validPrefix = false;
                    break;
                }

                cnt[x]--;
            }

            if (!validPrefix) {
                continue;
            }

            // At position i, choose the smallest
            // character greater than target[i].
            for (int c = prefix[i] - 'a' + 1; c < 26; c++) {

                if (cnt[c] == 0) {
                    continue;
                }

                // Build first half
                string firstHalf = prefix.substr(0, i);

                firstHalf += char('a' + c);

                cnt[c]--;

                // Fill remaining positions with
                // smallest possible characters.
                for (int x = 0; x < 26; x++) {

                    while (cnt[x] > 0) {
                        firstHalf += char('a' + x);
                        cnt[x]--;
                    }
                }

                // Build palindrome
                string ans = firstHalf;

                if (n % 2 == 1) {
                    ans += middle;
                }

                string rev = firstHalf;
                reverse(rev.begin(), rev.end());

                ans += rev;

                return ans;
            }
        }

        // No palindrome greater than target
        return "";
    }
};