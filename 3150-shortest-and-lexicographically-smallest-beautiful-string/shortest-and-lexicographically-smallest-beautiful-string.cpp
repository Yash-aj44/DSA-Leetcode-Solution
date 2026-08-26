class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.length();

        int left = 0;
        int ones = 0;

        int bestLen = INT_MAX;
        string ans = "";

        for (int right = 0; right < n; right++) {

            // Add current character
            if (s[right] == '1') {
                ones++;
            }

            // We have exactly k ones
            while (ones == k) {

                // Remove leading zeros
                while (left <= right && s[left] == '0') {
                    left++;
                }

                int len = right - left + 1;
                string current = s.substr(left, len);

                // Check shortest first
                if (len < bestLen) {
                    bestLen = len;
                    ans = current;
                }
                // Same length -> lexicographically smaller
                else if (len == bestLen && current < ans) {
                    ans = current;
                }

                // Remove the leftmost 1
                if (s[left] == '1') {
                    ones--;
                }

                left++;
            }
        }

        return ans;
    }
};