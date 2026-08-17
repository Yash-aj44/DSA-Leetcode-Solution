#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution {
private:
    int memo[501][501];
    
    int solve(int i, int j, const vector<int>& prefixSum) {
        // Base case: only 1 stone left, no further score can be gained
        if (i >= j) return 0;
        
        if (memo[i][j] != -1) return memo[i][j];
        
        int maxScore = 0;
        
        // Try all possible split points k where left part is [i..k] and right part is [k+1..j]
        for (int k = i; k < j; ++k) {
            int leftSum = prefixSum[k + 1] - prefixSum[i];
            int rightSum = prefixSum[j + 1] - prefixSum[k + 1];
            
            if (leftSum < rightSum) {
                // Bob throws away the right row
                maxScore = max(maxScore, leftSum + solve(i, k, prefixSum));
            } else if (rightSum < leftSum) {
                // Bob throws away the left row
                maxScore = max(maxScore, rightSum + solve(k + 1, j, prefixSum));
            } else {
                // Sums are equal, Alice chooses the maximum path
                int takeLeft = leftSum + solve(i, k, prefixSum);
                int takeRight = rightSum + solve(k + 1, j, prefixSum);
                maxScore = max({maxScore, takeLeft, takeRight});
            }
        }
        
        return memo[i][j] = maxScore;
    }

public:
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();
        
        // Initialize memoization array with -1
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                memo[i][j] = -1;
            }
        }
        
        // Build prefix sum array for O(1) subarray sum queries
        vector<int> prefixSum(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            prefixSum[i + 1] = prefixSum[i] + stoneValue[i];
        }
        
        return solve(0, n - 1, prefixSum);
    }
};