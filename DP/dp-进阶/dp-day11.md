### 安卓系统手势解锁

我们都知道安卓有个手势解锁的界面，是一个 `3 x 3` 的点所绘制出来的网格。用户可以设置一个 “解锁模式” ，通过连接特定序列中的点，形成一系列彼此连接的线段，每个线段的端点都是序列中两个连续的点。如果满足以下两个条件，则 `k` 点序列是有效的解锁模式：

- 解锁模式中的所有点 **互不相同** 。

- 假如模式中两个连续点的线段需要经过其他点的中心，那么要经过的点

   必须提前出现

在序列中（已经经过），不能跨过任何还未被经过的点。

- 例如，点 `5` 或 `6` 没有提前出现的情况下连接点 `2` 和 `9` 是有效的，因为从点 `2` 到点 `9` 的线没有穿过点 `5` 或 `6` 的中心。
- 然而，点 `2` 没有提前出现的情况下连接点 `1` 和 `3` 是无效的，因为从圆点 `1` 到圆点 `3` 的直线穿过圆点 `2` 的中心。



- **无效手势：**`[4,1,3,6]` ，连接点 1 和点 3 时经过了未被连接过的 2 号点。
- **无效手势：**`[4,1,9,2]` ，连接点 1 和点 9 时经过了未被连接过的 5 号点。
- **有效手势：**`[2,4,1,3,6]` ，连接点 1 和点 3 是有效的，因为虽然它经过了点 2 ，但是点 2 在该手势中之前已经被连过了。
- **有效手势：**`[6,5,4,1,9,2]` ，连接点 1 和点 9 是有效的，因为虽然它经过了按键 5 ，但是点 5 在该手势中之前已经被连过了。

给你两个整数，分别为 `m` 和 `n` ，那么请返回有多少种 **不同且有效的解锁模式** ，是 **至少** 需要经过 `m` 个点，但是 **不超过** `n` 个点的。

两个解锁模式 **不同** 需满足：经过的点不同或者经过点的顺序不同。



##### dfs

走马字的与八周的无需判断跨过的中心是否提前出现，而跨过其他点中心的需要额外判断

```c++
class Solution {
private: 
    int cnt = 0;
    int mi, ma;
    // 还可以走马的路径
    const int kDx1[16] = {0, 0, 1, 1, 1, -1, -1, -1, 1, 2, -1, -2, 1, 2, -1, -2};
    const int kDy1[16] = {1, -1, 1, 0, -1, 1, 0, -1, 2, 1, 2, 1, -2, -1, -2, -1};
    const int kDx2[8] = {0, 0, 2, 2, 2, -2, -2, -2};
    const int kDy2[8] = {2, -2, 2, 0, -2, 2, 0, -2};

public:
    int numberOfPatterns(int m, int n) {
        vector<vector<bool>> visited(3, vector<bool>(3));
        mi = m;
        ma = n;
        visited[0][0] = true;
        dfs(0, 0, 1, visited);
        visited[0][0] = false;
        
        visited[0][1] = true;
        dfs(0, 1, 1, visited);
        visited[0][1] = false;
        int cnt2 = cnt;

        visited[1][1] = true;
        dfs(1, 1, 1, visited);
        
        return cnt + cnt2 * 3;
    }

    void dfs(int x, int y, int depth, vector<vector<bool>>& visited) {
        
        if (depth >= mi) {
            cnt++;
        } 
        for (int i = 0; i < 16; i++) {
            int nX = x + kDx1[i], nY = y + kDy1[i];
            if (depth < ma && nX >= 0 && nX < 3 && nY >= 0 && nY < 3 && !visited[nX][nY]) {
                visited[nX][nY] = true;
                dfs(nX, nY, depth + 1, visited);
                visited[nX][nY] = false;
            }
        }

        for (int i = 0; i < 8; i++) {
            int nX = x + kDx2[i], nY = y + kDy2[i];
            if (depth < ma && nX >= 0 && nX < 3 && nY >= 0 && nY < 3 && !visited[nX][nY] && visited[x + kDx1[i]][y + kDy1[i]]) {
                visited[nX][nY] = true;
                dfs(nX, nY, depth + 1, visited);
                visited[nX][nY] = false;
            }
        }    
    }
};


```

