class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        vector<vector<int>> dp(k, vector<int>(k, 0));
        int ans = 0;

        for (int num : nums) {
            int x = num % k;
            for (int j = 0; j < k; ++j) {
                int y = (j - x + k) % k;
                dp[x][y] = dp[y][x] + 1;
                ans = max(ans, dp[x][y]);
            }
        }

        return ans;
    }
};

