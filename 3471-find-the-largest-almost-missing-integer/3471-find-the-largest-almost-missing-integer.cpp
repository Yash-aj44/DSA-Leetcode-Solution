class Solution {
public:
    int largestInteger(std::vector<int>& nums, int k) {
        int n = nums.size();
        std::unordered_map<int, int> freq;
        for (int x : nums) {
            freq[x]++;
        }

        // Case 1: k == n
        if (k == n) {
            int ans = -1;
            for (const auto& [val, count] : freq) {
                if (count >= 1) {
                    ans = std::max(ans, val);
                }
            }
            return ans;
        }

        // Case 2: k == 1
        if (k == 1) {
            int ans = -1;
            for (const auto& [val, count] : freq) {
                if (count == 1) {
                    ans = std::max(ans, val);
                }
            }
            return ans;
        }

        // Case 3: 1 < k < n
        // Only nums[0] and nums[n-1] can appear in exactly 1 subarray of size k
        int ans = -1;
        if (freq[nums[0]] == 1) ans = std::max(ans, nums[0]);
        if (freq[nums[n - 1]] == 1) ans = std::max(ans, nums[n - 1]);

        return ans;
    }
};