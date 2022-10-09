### 零钱兑换

给你一个整数数组 coins ，表示不同面额的硬币；以及一个整数 amount ，表示总金额。

计算并返回可以凑成总金额所需的 最少的硬币个数 。如果没有任何一种硬币组合能组成总金额，返回 -1 。

你可以认为每种硬币的数量是无限的。



##### 动态规划

设dp[i]为凑成总金额i所需要的最少的硬币个数，有：
$$
dp[i]=min(dp[i],dp[i-coins[j]]+1),coins[j]<=i
$$

```c++
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int Max=amount+1;
        vector<int> dp(Max,Max);
        dp[0]=0;
        for(int i=1;i<=amount;i++){
            for(int j=0;j<coins.size();j++){
                if(coins[j]<=i)
                    dp[i]=min(dp[i],dp[i-coins[j]]+1);
            }
        }
        return dp[amount]>amount?-1:dp[amount];
    }
};
```

