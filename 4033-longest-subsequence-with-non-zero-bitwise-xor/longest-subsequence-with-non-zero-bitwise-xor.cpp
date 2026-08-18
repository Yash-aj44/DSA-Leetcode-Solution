#include <vector>
#include <numeric>

class Solution {
public:
    int longestSubsequence(std::vector<int>& nums) {
        int totalXor = 0;
        bool hasNonZero = false;

        for (int num : nums) {
            totalXor ^= num;
            if (num != 0) {
                hasNonZero = true;
            }
        }

        // Case 1: All elements are 0
        if (!hasNonZero) {
            return 0;
        }

        // Case 2: XOR of all elements is already non-zero
        if (totalXor != 0) {
            return nums.size();
        }

        // Case 3: XOR of all elements is zero, remove 1 non-zero element
        return nums.size() - 1;
    }
};