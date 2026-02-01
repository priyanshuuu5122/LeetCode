class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        for(int i =1;i<nums.size();i++){
            nums[i]=nums[i] + nums[i-1];
        }
        return nums;


        
    }
};



// Traverse the array from left to right

// Keep adding the previous sum to the current element

// Store/update the result
