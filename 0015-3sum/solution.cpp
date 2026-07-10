#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
        std::vector<std::vector<int>> ans;
        std::sort(nums.begin(), nums.end());
        
        for (int i = 0; i < nums.size(); i++) {
            // Skip duplicate elements for the first position
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            
            int j = i + 1;
            int k = nums.size() - 1;
            
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                
                if (sum == 0) {
                    ans.push_back({nums[i], nums[j], nums[k]});
                    
                    // Skip duplicates for the second position
                    while (j < k && nums[j] == nums[j + 1]) j++;
                    // Skip duplicates for the third position
                    while (j < k && nums[k] == nums[k - 1]) k--;
                    
                    // Move both pointers inward after finding a valid triplet
                    j++;
                    k--;
                } else if (sum < 0) {
                    j++; // Sum is too small, move the left pointer right
                } else {
                    k--; // Sum is too large, move the right pointer left
                }
            }
        }
        return ans;
    }
};
