### 零钱兑换问题

##### 回溯：

枚举每一种可能的组合，但可以遇见的是会存在许多的重复计算，这就要用到在outline中讲到的「记忆化搜索」，其实将记忆化搜索的回溯改写为迭代形式就是「动态规划」。

```c++
class Solution {
public:
    vector<int> cnt;
    int traceback(vector<int>& coins,int rem){
        if(rem<0)
            return -1;
        if(rem==0)
            return 0;
        if(cnt[rem-1]!=0)
            return cnt[rem-1];
        int Min=INT_MAX;
        for(auto& coin:coins){
            int tmp=traceback(coins,rem-coin);
            if(tmp>=0&&tmp<Min)
                Min=tmp+1;
        }
        cnt[rem-1]=Min==INT_MAX?-1:Min;
        return cnt[rem-1];
    }
    int coinChange(vector<int>& coins, int amount) {
        if(amount==0)
            return 0;
        cnt.resize(amount);
        return traceback(coins,amount);
    }
};
```



##### 动态规划：

将上述的过程转写为迭代形式：

其中dp[i]代表组合出amount为i的硬币的最小个数，当i等于0时，不需要任何硬币就能凑出0，所以dp[0]=0；对于任意大于0的i，有：
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

