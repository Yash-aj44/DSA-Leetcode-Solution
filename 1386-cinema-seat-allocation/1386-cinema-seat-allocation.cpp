#include <vector>
#include <unordered_map>

class Solution {
public:
    int maxNumberOfFamilies(int n, std::vector<std::vector<int>>& reservedSeats) {
        // Hash map to store row index -> bitmask of reserved seats
        std::unordered_map<int, int> reservedMap;
        
        for (const auto& seat : reservedSeats) {
            int row = seat[0];
            int col = seat[1];
            // Only care about seats 2 through 9
            if (col >= 2 && col <= 9) {
                reservedMap[row] |= (1 << (col - 1));
            }
        }
        
        // Start with maximum possible groups if all rows were empty
        int totalGroups = (n - reservedMap.size()) * 2;
        
        // Bitmasks for the 4-seat blocks
        int leftBlock   = (1 << 1) | (1 << 2) | (1 << 3) | (1 << 4); // Seats 2, 3, 4, 5
        int middleBlock = (1 << 3) | (1 << 4) | (1 << 5) | (1 << 6); // Seats 4, 5, 6, 7
        int rightBlock  = (1 << 5) | (1 << 6) | (1 << 7) | (1 << 8); // Seats 6, 7, 8, 9
        
        for (const auto& [row, mask] : reservedMap) {
            bool leftPossible = (mask & leftBlock) == 0;
            bool rightPossible = (mask & rightBlock) == 0;
            
            if (leftPossible && rightPossible) {
                totalGroups += 2;
            } else if (leftPossible || rightPossible || (mask & middleBlock) == 0) {
                totalGroups += 1;
            }
        }
        
        return totalGroups;
    }
};