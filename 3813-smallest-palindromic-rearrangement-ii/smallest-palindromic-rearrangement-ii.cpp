class Solution {
public:
    const long long CAP = 1000000LL + 1;

    long long C(int n, int r) {
        if (r < 0 || r > n) return 0;
        r = min(r, n - r);
        __int128 res = 1;
        for (int i = 1; i <= r; i++) {
            res = res * (n - r + i) / i;
            if (res > CAP) return CAP;
        }
        return (long long)res;
    }

    long long ways(vector<int> &cnt) {
        long long res = 1;
        int rem = 0;
        for (int c : cnt) {
            if (!c) continue;
            long long comb = C(rem + c, c);
            res = min(CAP, res * comb);
            rem += c;
        }
        return res;
    }

    string smallestPalindrome(string s, int k) {
        vector<int> cnt(26);
        for (char c : s) cnt[c - 'a']++;

        vector<int> half(26);
        char mid = 0;
        int len = 0;

        for (int i = 0; i < 26; i++) {
            half[i] = cnt[i] / 2;
            len += half[i];
            if (cnt[i] & 1) mid = char('a' + i);
        }

        if (ways(half) < k) return "";

        string left;
        for (int pos = 0; pos < len; pos++) {
            for (int i = 0; i < 26; i++) {
                if (!half[i]) continue;
                half[i]--;
                long long w = ways(half);
                if (k > w) {
                    k -= w;
                    half[i]++;
                } else {
                    left.push_back(char('a' + i));
                    break;
                }
            }
        }

        string right = left;
        reverse(right.begin(), right.end());
        return mid ? left + string(1, mid) + right : left + right;
    }
    
};