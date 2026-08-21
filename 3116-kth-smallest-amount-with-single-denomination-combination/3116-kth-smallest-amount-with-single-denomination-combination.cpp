class Solution {
public:

    using ll = long long;

    ll gcd_ll(ll a, ll b) {
        while (b) {
            ll temp = a % b;
            a = b;
            b = temp;
        }
        return a;
    }

    ll lcm_ll(ll a, ll b) {
        return a / gcd_ll(a, b) * b;
    }

    ll countAmounts(ll x, vector<int>& coins) {

        int n = coins.size();
        ll count = 0;

        // Try every subset of coins
        for (int mask = 1; mask < (1 << n); mask++) {

            ll lcm = 1;
            int bits = 0;

            for (int i = 0; i < n; i++) {

                if (mask & (1 << i)) {

                    bits++;

                    lcm = lcm_ll(lcm, coins[i]);

                    if (lcm > x)
                        break;
                }
            }

            if (lcm > x)
                continue;

            ll multiples = x / lcm;

            if (bits % 2 == 1)
                count += multiples;
            else
                count -= multiples;
        }

        return count;
    }

    long long findKthSmallest(vector<int>& coins, long long k) {

        ll low = 1;

        ll minCoin = *min_element(coins.begin(), coins.end());

        ll high = minCoin * k;

        while (low < high) {

            ll mid = low + (high - low) / 2;

            if (countAmounts(mid, coins) >= k)
                high = mid;
            else
                low = mid + 1;
        }

        return low;
    }
};