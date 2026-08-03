class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        std::unordered_map<int, int> seen{};

        // target - current = diff
        // seen = [value : index] 


        for(int i{}; i < nums.size(); ++i){
        
            int curr = nums[i];
            int diff = target - curr;

            if(seen.contains(diff)){
                return {seen[diff], i};
            } 
            seen[curr] = i;
        }
        return {};
    }
};