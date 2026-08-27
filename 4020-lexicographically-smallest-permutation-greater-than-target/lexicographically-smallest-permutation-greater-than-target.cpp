class Solution {
public:
    string lexGreaterPermutation(string s, string target) {

        vector<int> freq(26, 0);

        for (char c : s) {
            freq[c - 'a']++;
        }

        string prefix = "";

        for (int i = 0; i < target.size(); i++) {

            int x = target[i] - 'a';

            // Keep this character equal to target
            if (freq[x] > 0) {

                freq[x]--;
                prefix += target[i];
            }
            else {

                // Find the smallest character
                // greater than target[i]
                for (int c = x + 1; c < 26; c++) {

                    if (freq[c] > 0) {

                        string ans = prefix;
                        ans += char('a' + c);

                        freq[c]--;

                        // Put remaining characters
                        // in smallest possible order
                        for (int j = 0; j < 26; j++) {
                            while (freq[j] > 0) {
                                ans += char('a' + j);
                                freq[j]--;
                            }
                        }

                        return ans;
                    }
                }

                // Can't make the answer greater at this point.
                // Need to backtrack.
                break;
            }
        }

        // Backtracking:
        // Try changing a position from right to left.

        for (int i = target.size() - 1; i >= 0; i--) {

            vector<int> count(26, 0);

            for (char c : s) {
                count[c - 'a']++;
            }

            // Match target[0 ... i-1]
            bool possible = true;

            for (int j = 0; j < i; j++) {

                int x = target[j] - 'a';

                if (count[x] == 0) {
                    possible = false;
                    break;
                }

                count[x]--;
            }

            if (!possible)
                continue;

            // Find smallest character greater than target[i]
            int x = target[i] - 'a';

            for (int c = x + 1; c < 26; c++) {

                if (count[c] > 0) {

                    string ans = target.substr(0, i);

                    ans += char('a' + c);

                    count[c]--;

                    // Smallest possible suffix
                    for (int j = 0; j < 26; j++) {
                        while (count[j] > 0) {
                            ans += char('a' + j);
                            count[j]--;
                        }
                    }

                    return ans;
                }
            }
        }

        return "";
    }
};