class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int cnt[3] = {0, 0, 0};

        for (int x : stones) {
            cnt[x % 3]++;
        }

        int zero = cnt[0];
        int one = cnt[1];
        int two = cnt[2];

        // Alice starts with a remainder-1 stone
        bool startOne = false;

        if (one > 0) {
            int a = one - 1;

            int pairs = min(a, two);
            int len = 1 + pairs * 2;

            a -= pairs;
            two -= pairs;

            if (a > 0) {
                len++;
                a--;
            }

            len += zero;

            if (len % 2 == 1 && (a + two > 0)) {
                startOne = true;
            }
        }

        // Alice starts with a remainder-2 stone
        bool startTwo = false;

        if (cnt[2] > 0) {
            int a = cnt[2] - 1;
            int b = cnt[1];

            int pairs = min(a, b);
            int len = 1 + pairs * 2;

            a -= pairs;
            b -= pairs;

            if (a > 0) {
                len++;
                a--;
            }

            len += zero;

            if (len % 2 == 1 && (a + b > 0)) {
                startTwo = true;
            }
        }

        return startOne || startTwo;
    }
};