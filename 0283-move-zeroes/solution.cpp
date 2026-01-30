class Solution {
public:
    void moveZeroes(vector<int>& nums) {

        int pos = 0;   // position for next non-zero

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                nums[pos] = nums[i];
                pos++;
            }
        }

        // fill remaining positions with zero
        while (pos < nums.size()) {
            nums[pos] = 0;
            pos++;
        }
    }
};

