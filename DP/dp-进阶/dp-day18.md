### 石子游戏

Alice 和 Bob 用几堆石子在做游戏。几堆石子排成一行，每堆石子都对应一个得分，由数组 `stoneValue` 给出。

Alice 和 Bob 轮流取石子，**Alice** 总是先开始。在每个玩家的回合中，该玩家可以拿走剩下石子中的的前 **1、2 或 3 堆石子** 。比赛一直持续到所有石头都被拿走。

每个玩家的最终得分为他所拿到的每堆石子的对应得分之和。每个玩家的初始分数都是 **0** 。比赛的目标是决出最高分，得分最高的选手将会赢得比赛，比赛也可能会出现平局。

假设 Alice 和 Bob 都采取 **最优策略** 。如果 Alice 赢了就返回 *"Alice"* *，*Bob 赢了就返回 *"Bob"，*平局（分数相同）返回 *"Tie"* 。



##### 动态规划

若f[i]表示还剩下i，i+1，...，n-1堆石子时，当前玩家能拿走的最多石子数目，有

- 如果当前玩家选择了拿走一堆石子，那么留给下个玩家的状态为f[i+1]，表示他能拿走的最多石子，则此时当前玩家可以拿走的石子数量为sum(i+1,n-1)-f[i+1]，再加上拿走的那一堆石子stoneValue[i],则可以拿走的石子数量可以简化为sum(i,n-1)-f[i+1].
- 如果当前玩家选择拿走两堆石子，那么留给下个玩家的状态为f[i+2],表示他最多能拿走f[i+2]枚石子，则当前玩家能拿走的石子数为sum(i,n-1)-f[i+2].
- 如果当前玩家选择拿走三堆石子，那么留给下个玩家的状态为f[i+3],表示他最多能拿走f[i+3]枚石子，则当前玩家能拿走的石子数为sum(i,n-1)-f[i+3].

则当前玩家只需选择能拿走最多石子的策略，就是「最优策略」。

在求解时，可以先计算出后缀和，状态转移方程为：
$$
f[i]=max(sum(i,n-1)-f[j])
	\\=sum(i,n-1)-min(f[j]),j\in[i+1,i+3]
$$

```c++
class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        
        vector<int> suffix_sum(n);
        suffix_sum[n - 1] = stoneValue[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            suffix_sum[i] = suffix_sum[i + 1] + stoneValue[i];
        }

        vector<int> f(n + 1);
        // 边界情况，当没有石子时，分数为 0
        // 为了代码的可读性，显式声明
        f[n] = 0;
        for (int i = n - 1; i >= 0; --i) {
            int bestj = f[i + 1];
            for (int j = i + 2; j <= i + 3 && j <= n; ++j) {
                bestj = min(bestj, f[j]);
            }
            f[i] = suffix_sum[i] - bestj;
        }
        
        int total = accumulate(stoneValue.begin(), stoneValue.end(), 0);
        if (f[0] * 2 == total) {
            return "Tie";
        }
        else {
            return f[0] * 2 > total ? "Alice" : "Bob";
        }
    }
};

```

