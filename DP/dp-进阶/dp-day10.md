### 摘樱桃

一个N x N的网格`(grid)` 代表了一块樱桃地，每个格子由以下三种数字的一种来表示：

- 0 表示这个格子是空的，所以你可以穿过它。
- 1 表示这个格子里装着一个樱桃，你可以摘到樱桃然后穿过它。
- -1 表示这个格子里有荆棘，挡着你的路。

你的任务是在遵守下列规则的情况下，尽可能的摘到最多樱桃：

- 从位置 (0, 0) 出发，最后到达 (N-1, N-1) ，只能向下或向右走，并且只能穿越有效的格子（即只可以穿过值为0或者1的格子）；
- 当到达 (N-1, N-1) 后，你要继续走，直到返回到 (0, 0) ，只能向上或向左走，并且只能穿越有效的格子；
- 当你经过一个格子且这个格子包含一个樱桃时，你将摘到樱桃并且这个格子会变成空的（值变为0）；
- 如果在 (0, 0) 和 (N-1, N-1) 之间不存在一条可经过的路径，则没有任何一个樱桃能被摘到。



```c++
class Solution {
public:
    int cherryPickup(vector<vector<int>> &grid) {
        int n = grid.size();
        vector<vector<int>> f(n, vector<int>(n, INT_MIN));
        f[0][0] = grid[0][0];
        for (int k = 1; k < n * 2 - 1; ++k) {
            for (int x1 = min(k, n - 1); x1 >= max(k - n + 1, 0); --x1) {
                for (int x2 = min(k, n - 1); x2 >= x1; --x2) {
                    int y1 = k - x1, y2 = k - x2;
                    if (grid[x1][y1] == -1 || grid[x2][y2] == -1) {
                        f[x1][x2] = INT_MIN;
                        continue;
                    }
                    int res = f[x1][x2]; // 都往右
                    if (x1) {
                        res = max(res, f[x1 - 1][x2]); // 往下，往右
                    }
                    if (x2) {
                        res = max(res, f[x1][x2 - 1]); // 往右，往下
                    }
                    if (x1 && x2) {
                        res = max(res, f[x1 - 1][x2 - 1]); // 都往下
                    }
                    res += grid[x1][y1];
                    if (x2 != x1) { // 避免重复摘同一个樱桃
                        res += grid[x2][y2];
                    }
                    f[x1][x2] = res;
                }
            }
        }
        return max(f.back().back(), 0);
    }
};

```

