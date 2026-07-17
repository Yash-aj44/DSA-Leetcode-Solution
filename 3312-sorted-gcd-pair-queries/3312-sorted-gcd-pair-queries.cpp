class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int mx = *max_element(nums.begin(), nums.end());

        vector<int> freq(mx + 1, 0);
        for (int x : nums)
            freq[x]++;

        // cnt[d] = numbers divisible by d
        vector<long long> cnt(mx + 1, 0);

        for (int d = 1; d <= mx; d++) {
            for (int m = d; m <= mx; m += d)
                cnt[d] += freq[m];
        }

        // exact gcd counts
        vector<long long> gcdCnt(mx + 1, 0);

        for (int d = mx; d >= 1; d--) {
            long long c = cnt[d];
            gcdCnt[d] = c * (c - 1) / 2;

            for (int m = d + d; m <= mx; m += d)
                gcdCnt[d] -= gcdCnt[m];
        }

        // prefix counts
        vector<long long> pref(mx + 1, 0);
        for (int i = 1; i <= mx; i++)
            pref[i] = pref[i - 1] + gcdCnt[i];

        vector<int> ans;

        for (long long k : queries) {
            int g = lower_bound(pref.begin() + 1, pref.end(), k + 1) - pref.begin();
            ans.push_back(g);
        }

        return ans;
    }
};