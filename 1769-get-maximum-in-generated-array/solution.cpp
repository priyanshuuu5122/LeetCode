class Solution {
public:
    int getMaximumGenerated(int n) {
        std::array<int, 101> data = {};
        if (n) data[1] = 1;
        for (int i = 1; i <= n; ++i) {
            if (i * 2 <= n) data[i * 2] = data[i];
            if (i * 2 + 1 <= n) data[i * 2 + 1] = data[i] + (i + 1 < n ? data[i + 1] : 0);
        }
        return *std::max_element(data.begin(), data.end());
    }
};
