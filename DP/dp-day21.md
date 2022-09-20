### lc-377

给你一个由 不同 整数组成的数组 nums ，和一个目标整数 target 。请你从 nums 中找出并返回总和为 target 的元素组合的个数。

题目数据保证答案符合 32 位整数范围。

 

示例 1：

输入：nums = [1,2,3], target = 4
输出：7
解释：
所有可能的组合为：
(1, 1, 1, 1)
(1, 1, 2)
(1, 2, 1)
(1, 3)
(2, 1, 1)
(2, 2)
(3, 1)
请注意，顺序不同的序列被视作不同的组合。



##### 方法1:回溯

可以回溯枚举出所有可能的结果，但我们可以画出递归树，发现有很多元素都被重复计算了，故可以使用「记忆化搜索」来降低时间复杂度。



##### 方法2:动态规划

将上述的「记忆化搜索」过程转写为dp形式，可以定义dp[i]的含义为：构成i的所有可能的组合的个数，则对于dp[0]，由于能且仅能不选择任何数（数据范围为1到1000）这一种情况能得到0，所以dp[0]=1，而对于任意dp[i] (i从1到target)有：
$$
dp[i]=dp[i]+dp[i-num],num<=i
$$

```c++
int combinationSum4(vector<int>& nums,int target){
	vector<int> dp(target+1);
	dp[0]=1;
	for(int i=1;i<=target;i++){
		for(auto& num:nums){
			if(num<=i && dp[i-num]<INT_MAX-dp[i])
				dp[i]+=dp[i-num];
		}
	}
	return dp[target];
}
```

