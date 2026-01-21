class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans;

        for (int x : nums) {
            // Even → impossible
            if (x % 2 == 0) {
                ans.push_back(-1);
                continue;
            }

            int cnt = 0;
            int temp = x;

            // count trailing 1s
            while (temp & 1) {
                cnt++;
                temp >>= 1;
            }

            // remove (cnt-1) trailing 1s
            int result = x - (1 << (cnt - 1));
            ans.push_back(result);
        }

        return ans;
    }
};

