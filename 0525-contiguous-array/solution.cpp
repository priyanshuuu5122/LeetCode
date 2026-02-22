class Solution {
public:
    int findMaxLength(vector<int>& nums) {

        int n = nums.size();

        /*
        STEP 1: Convert all 0s into -1.

        Reason:
        We want equal number of 0s and 1s.
        If we treat:
            1 -> +1
            0 -> -1

        Then a subarray with equal 0s and 1s will have total sum = 0.
        So now the problem becomes finding the longest subarray with sum zero.
        */

        for(int i = 0; i < n; i++) {
            if(nums[i] == 0) {
                nums[i] = -1;
            }
        }

        /*
        STEP 2: Create a hashmap to store prefix sum.

        Map stores:
            prefix_sum -> first index where this sum appears

        Why store first occurrence?
        Because when the same sum appears again later,
        the distance between them is maximum.
        */

        unordered_map<int, int> mp;

        /*
        Important initialization:

        If prefix sum becomes 0 at index i,
        then subarray from index 0 to i is balanced.

        So we pretend sum 0 occurred at index -1.
        */
        mp[0] = -1;

        int sum = 0;      // running prefix sum
        int maxLen = 0;   // answer

        /*
        STEP 3: Traverse the array and update prefix sum.
        */

        for(int i = 0; i < n; i++) {

            // Update running sum
            sum += nums[i];

            /*
            If we have seen this sum before,
            it means the subarray between previous index and current index
            has sum = 0 (balanced).
            */
            if(mp.find(sum) != mp.end()) {

                // length of balanced subarray
                int length = i - mp[sum];

                // update answer
                maxLen = max(maxLen, length);
            }
            else {
                /*
                Store the first occurrence of this sum.
                Do NOT overwrite — we want earliest index.
                */
                mp[sum] = i;
            }
        }

        return maxLen;
    }
};



        
        
 
