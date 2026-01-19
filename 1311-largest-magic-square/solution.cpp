class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        
        vector<vector<int>> row(m, vector<int>(n+1, 0));
        vector<vector<int>> col(m+1, vector<int>(n, 0));
        
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++) {
                row[i][j+1] = row[i][j] + grid[i][j];
                col[i+1][j] = col[i][j] + grid[i][j];
            }

        auto getRow = [&](int r, int c1, int c2){
            return row[r][c2] - row[r][c1];
        };
        auto getCol = [&](int c, int r1, int r2){
            return col[r2][c] - col[r1][c];
        };

        int maxSize = min(m, n);
        for(int k = maxSize; k >= 2; k--) {
            for(int i = 0; i + k <= m; i++) {
                for(int j = 0; j + k <= n; j++) {
                    int target = getRow(i, j, j+k);
                    bool ok = true;

                    for(int r = i; r < i+k && ok; r++)
                        if(getRow(r, j, j+k) != target) ok = false;

                    for(int c = j; c < j+k && ok; c++)
                        if(getCol(c, i, i+k) != target) ok = false;

                    int d1 = 0, d2 = 0;
                    for(int t = 0; t < k; t++) {
                        d1 += grid[i+t][j+t];
                        d2 += grid[i+t][j+k-1-t];
                    }

                    if(ok && d1 == target && d2 == target)
                        return k;
                }
            }
        }
        return 1;
    }
};

