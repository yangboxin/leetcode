### 删除回文子数组

给你一个整数数组 `arr`，每一次操作你都可以选择并删除它的一个 **回文** 子数组 `arr[i], arr[i+1], ..., arr[j]`（ `i <= j`）。

注意，每当你删除掉一个子数组，右侧元素都会自行向前移动填补空位。

请你计算并返回从数组中删除所有数字所需的最少操作次数。



##### 区间dp

 dp的目标是将一个区间删除完毕的最小代价；从较小的区间开始，易知长为1的区间代价一定为1，长为2的区间为1或2，取决于是否回文。 对一个l >= 3的区间 [i, j], 我们需要考虑两种情况:

1. 这个区间最小的删除方案是先删除[i, k]再删除[k + 1, j]， 其中 i <= k < j. 写法算是区间dp的基本操作：

   ​    for(int k = 0; k < len; k++)

   ​        if(dp[i] [i + len] > dp[i] [i + k] + dp[i + k + 1] [i + len])

   ​            dp[i] [i + len] = dp[i] [i + k] + dp[i + k + 1] [i + len];

2. 这个区间最小的删除方案是先剔除其中的部分元素，再作为一个回文串一并删除。 其实判断条件也好理解：只要区间[i, j]的左右端是相同数值，则将这个区间删除的代价和将[i + 1, j - 1]删除的代价就是相同的; 不管对[i + 1, j - 1]如何操作，在最后一次删除的时候就可以把两个端点带上而不用增加删除的代价。

```c++
class Solution {
public:
    int minimumMoves(vector<int>& arr) {
        int dp[101][101];
        for(int i = 0; i < arr.size(); i++)
            dp[i][i] = 1;
        for(int i = 0; i < arr.size() - 1; i++)
            if(arr[i] == arr[i + 1])
                dp[i][i + 1] = 1;
            else
                dp[i][i + 1] = 2;
        for(int len = 2; len < arr.size(); len++)
            for(int i = 0; i < arr.size() - len; i++)
            {
                dp[i][i + len] = len + 1;
                for(int k = 0; k < len; k++)
                    if(dp[i][i + len] > dp[i][i + k] + dp[i + k + 1][i + len])
                        dp[i][i + len] = dp[i][i + k] + dp[i + k + 1][i + len];
                if(arr[i] == arr[i + len] && dp[i][i + len] > dp[i + 1][i + len - 1])
                    dp[i][i + len] = dp[i + 1][i + len - 1];
            }
        return dp[0][arr.size() - 1];
    }
};
```

