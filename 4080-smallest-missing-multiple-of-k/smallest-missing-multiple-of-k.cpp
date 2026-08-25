class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> s;

        // Store all numbers
        for (int x : nums) {
            s.insert(x);
        }

        // Check multiples of k
        int multiple = k;

        while (s.count(multiple)) {
            multiple += k;
        }

        return multiple;
    }
};