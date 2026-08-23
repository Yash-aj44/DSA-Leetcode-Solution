class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();

        int diff = 0;
        int leftQ = 0;
        int rightQ = 0;

        // First half
        for (int i = 0; i < n / 2; i++) {
            if (num[i] == '?') {
                leftQ++;
            } else {
                diff += num[i] - '0';
            }
        }

        // Second half
        for (int i = n / 2; i < n; i++) {
            if (num[i] == '?') {
                rightQ++;
            } else {
                diff -= num[i] - '0';
            }
        }

        // Odd number of '?' -> Alice wins
        if ((leftQ + rightQ) % 2 == 1) {
            return true;
        }

        // Bob wins only if he can exactly cancel the difference
        return 2 * diff != 9 * (rightQ - leftQ);
    }
};