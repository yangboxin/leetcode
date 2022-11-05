### 角矩形的数量

给定一个只包含 `0` 和 `1` 的 `m x n` 整数矩阵 `grid` ，返回 *其中 「**角矩形 」**的数量* 。

一个**「角矩形」**是由四个不同的在矩阵上的 `1` 形成的 **轴对齐** 的矩形。注意只有角的位置才需要为 `1`。

**注意：**4 个 `1` 的位置需要是不同的。



##### 动态规划

定义dp[i] [j]表示从第一行到当前行，i和j两个点都为1的行的个数

```c++
class Solution {
public:
    int countCornerRectangles(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j]) {
                    for (int k = j + 1; k < n; k++) {
                        if (grid[i][k]) {
                            ans += dp[j][k];
                            dp[j][k]++;
                        }
                    }
                }
            }
        }
        return ans;
    }
};
```

