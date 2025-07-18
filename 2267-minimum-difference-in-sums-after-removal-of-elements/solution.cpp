class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        int n = nums.size() / 3;

        // prefix[i] stores minimum sum of n largest elements in nums[0..i]
        vector<long long> prefixSum(3 * n, 0);
        priority_queue<int> maxHeap;
        long long prefixTotal = 0;

        for (int i = 0; i < 3 * n; ++i) {
            maxHeap.push(nums[i]);
            prefixTotal += nums[i];
            if ((int)maxHeap.size() > n) {
                prefixTotal -= maxHeap.top();
                maxHeap.pop();
            }
            if ((int)maxHeap.size() == n) {
                prefixSum[i] = prefixTotal;
            } else {
                prefixSum[i] = LLONG_MAX; // invalid prefix
            }
        }

        // suffix[i] stores maximum sum of n smallest elements in nums[i..]
        vector<long long> suffixSum(3 * n, 0);
        priority_queue<int, vector<int>, greater<int>> minHeap;
        long long suffixTotal = 0;

        for (int i = 3 * n - 1; i >= 0; --i) {
            minHeap.push(nums[i]);
            suffixTotal += nums[i];
            if ((int)minHeap.size() > n) {
                suffixTotal -= minHeap.top();
                minHeap.pop();
            }
            if ((int)minHeap.size() == n) {
                suffixSum[i] = suffixTotal;
            } else {
                suffixSum[i] = LLONG_MIN; // invalid suffix
            }
        }

        // Find minimum difference between prefix[i] and suffix[i+1]
        long long res = LLONG_MAX;
        for (int i = n - 1; i < 2 * n; ++i) {
            if (prefixSum[i] != LLONG_MAX && suffixSum[i + 1] != LLONG_MIN) {
                res = min(res, prefixSum[i] - suffixSum[i + 1]);
            }
        }

        return res;
    }
};

