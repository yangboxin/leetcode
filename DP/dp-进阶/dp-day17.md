### 盈利计划

集团里有 `n` 名员工，他们可以完成各种各样的工作创造利润。

第 `i` 种工作会产生 `profit[i]` 的利润，它要求 `group[i]` 名成员共同参与。如果成员参与了其中一项工作，就不能参与另一项工作。

工作的任何至少产生 `minProfit` 利润的子集称为 **盈利计划** 。并且工作的成员总数最多为 `n` 。

有多少种计划可以选择？因为答案很大，所以 **返回结果模** `10^9 + 7` **的值**。



##### 变种背包问题

传统背包问题可以用二维动态规划解决，一维表示物品限制，一维表示容量限制，而此题显然可以用三维动态规划解决，三个维度分别表示：当前可选择的工作，已选择的小组员工人数，目前状态的工作获利下限。

根据描述可建立dp[i] [j] [k]表示在前i个工作中选择了j个员工，并且满足工作利润至少为k的情况下盈利计划的总数目。假设group数组长len，最终答案为：
$$
\sum^{n}_{i=0} dp[len][i][minProfit]
$$
初始化dp[0] [0] [0]=1.对于每个工作i，根据当前工作人数上限j，分为能开展工作和不能开展工作两种情况：

- 如果无法开展当前工作i，显然
  $$
  dp[i][j][k]=dp[i-1][j][k]
  $$

- 如果能开展工作，设当前小组人数为group[i]，工作获利为profit[i],那么：

$$
dp[i][j][k]=dp[i-1][j][k]+dp[i-1][j-group[i]][max(0,k-profit[i])]
$$

同时，显然每个状态只与上一个有关，可以优化掉一维空间

```c++
class Solution {
    public int profitableSchemes(int n, int minProfit, int[] group, int[] profit) {
        int[][] dp = new int[n + 1][minProfit + 1];
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 1;
        }
        int len = group.length, MOD = (int)1e9 + 7;
        for (int i = 1; i <= len; i++) {
            int members = group[i - 1], earn = profit[i - 1];
            for (int j = n; j >= members; j--) {
                for (int k = minProfit; k >= 0; k--) {
                    dp[j][k] = (dp[j][k] + dp[j - members][Math.max(0, k - earn)]) % MOD;
                }
            }
        }
        return dp[n][minProfit];
    }
}

```

