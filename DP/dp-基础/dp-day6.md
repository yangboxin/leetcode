### 经过一次操作后的最大子数组和

 你有一个整数数组 nums。你只能将一个元素 nums[i] 替换为 nums[i] * nums[i]。

返回替换后的最大子数组和。

```
示例 1：

输入：nums = [2,-1,-4,-3]
输出：17
解释：你可以把-4替换为16(-4*(-4))，使nums = [2,-1,16,-3]. 现在，最大子数组和为 2 + -1 + 16 = 17.
```



##### 动态规划

分别计算将每个位置操作后和不操作可能得到的最大子数组和。

定义dp[i] [0]的含义为从0～i范围内，不操作所能得到的最大子数组和；

dp[i] [1]的含义为从0到i，替换第i位后得到的最大子数组和。

显然dp[0] [0]=nums[0],dp[0] [1]=nums[0]*nums[0].

而对于任意大于i>=1的dp[i] [0],dp[i] [1]有：
$$
dp[i][0]=max(dp[i-1][0],0)+nums[i];\\
dp[i][1]=max(max(dp[i-1][0],0)+nums[i]*nums[i],dp[i-1][1]+nums[i])
$$
并且注意到每个i的状态只与前一个有关，可以用滚动数组优化



```c++
class Solution{
public:
    int maxSumAfterOperation(vector<int>& nums){
        int n=nums.size();
        vector<int> dp(2);
        dp[0]=nums[0],dp[1]=nums[0]*nums[0];
        int res=dp[1];
        for(int i=1;i<n;i++){
            vector<int> tmp(2);
            tmp[0]=max(dp[0],0)+nums[i];
            tmp[1]=max(max(dp[0],0)+nums[i]*nums[i],dp[1]+nums[i]);
            res=max(res,tmp[1]);
            dp=move(tmp);
        }
        return res;
    }
};
```

