class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        vector<int> freq(10, 0);

        // Count how many times each digit appears
        for (int digit : digits) {
            freq[digit]++;
        }

        int count = 0;

        // First digit: 1-9 (cannot be 0)
        for (int i = 1; i <= 9; i++) {

            // Second digit: 0-9
            for (int j = 0; j <= 9; j++) {

                // Third digit must be even
                for (int k = 0; k <= 8; k += 2) {

                    // Check if digits are available
                    vector<int> used(10, 0);

                    used[i]++;
                    used[j]++;
                    used[k]++;

                    bool possible = true;

                    for (int d = 0; d <= 9; d++) {
                        if (used[d] > freq[d]) {
                            possible = false;
                            break;
                        }
                    }

                    if (possible) {
                        count++;
                    }
                }
            }
        }

        return count;
    }
};