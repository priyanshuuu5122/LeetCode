class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans;

        for (int p : nums) {
            int value = -1;

            // try all possible values from smallest
            for (int a = 0; a <= p; a++) {
                if ( (a | (a + 1)) == p ) {
                    value = a;
                    break;
                }
            }

            ans.push_back(value);
        }

        return ans;
    }
};

