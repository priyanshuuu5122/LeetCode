class Solution {
public:
    bool canJump(vector<int>& nums) {
        int max_reach = 0;
        int n = nums.size();
        
        for (int i = 0; i < n; ++i) {
            // If the current index is unreachable, we can't move forward
            if (i > max_reach) {
                return false;
            }
            
            // Update the maximum reach possible so far
            max_reach = std::max(max_reach, i + nums[i]);
            
            // Optimization: If we can already reach the last index, stop early
            if (max_reach >= n - 1) {
                return true;
            }
        }
        
        return true;
    }
};
