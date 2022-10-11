### 分割等和子集

给你一个 **只包含正整数** 的 **非空** 数组 `nums` 。请你判断是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。



##### 动态规划

首先需要判断给定的数组是否可以分成两个元素和相等的子集，对于一个数组nums，首先需要满足其大小大于等于2，才有可能分成两个等和的子集，其次需要整个数组的元素和为偶数，以及数组中最大的元素不超过整个数组元素和的一半，同时计算出整个数组元素和的一半target。

设动态规划数组dp[i] [j]表示从0到i选取任意数字是否能获得一个元素和为j的集合，讨论其初始状态：对于dp[i] [0]，可以不选任何数字得到一个和为0的空集；对于dp[0] [nums[0]]，可以选择第一个元素得到元素和为nums[0]的集合。所以有dp[i] [0]=true,dp[0] [nums[0]]=true.

对于其余任意dp[i] [j]，可以分为两类讨论：

1. 当nums[i]>j时，不能选择当前元素，dp[i] [j]=dp[i-1] [j]
2. 当nums[i]<=j时，可以选择当前元素，同时也可以不选择，所以dp[i] [j]=dp[i-1] [j] | dp[i-1] [j-nums[i]]

注意到每个dp[i] [j]的状态只与i-1个元素有关，可以用滚动数组优化空间复杂度。



```c++
class Solution {
public:
    bool canPartition(vector<int>& nums){
      int n=nums.size();
      if(n<2)
        return false;
      int total=accumulate(nums.begin(), nums.end(),0);
      if(total&1)
        return false;
      int target=total>>1;
      int maxelem=*max_element(nums.begin(), nums.end());
      if(maxelem>target)
        return false;
      vector<int> dp(target+1,0);
      dp[nums[0]]=1;
      for(int i=1;i<n;i++){
            int num=nums[i];
        for(int j=target;j>=num;j--){
          dp[j]|= dp[j-nums[i]];
        }
      }
      return dp[target];
    }
};
```

