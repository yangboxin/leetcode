### 最长递增子序列的个数

给定一个未排序的整数数组 nums ， 返回最长递增子序列的个数 。

注意 这个数列必须是 严格 递增的。

 

```
示例 1:

输入: [1,3,5,4,7]
输出: 2
解释: 有两个最长递增子序列，分别是 [1, 3, 4, 7] 和[1, 3, 5, 7]。
```



##### 动态规划

使用动态规划计算出最长递增子序列的大小maxlen，并计算有多少个长度为maxlen的递增子序列。

dp[i]表示从0到i的最长递增子序列的大小。

cnt[i]表示从0到i的最长递增子序列的个数。

```c++
int findNumberOfLIS(vector<int>& nums){
	int n=nums.size(),maxlen=0,res=0;
	vector<int> dp(n),cnt(n);
	for(int i=0;i<n;i++){
		dp[i]=1;
		cnt[i]=1;
		for(int j=0;j<i;j++){
			if(nums[j]<nums[i]){
				if(dp[j]+1>dp[i]){
					dp[i]=dp[j]+1;
					cnt[i]=cnt[j];
				}
				else if(dp[j]+1==dp[i])
					cnt[i]+=cnt[j];
			}
		}
		if(dp[i]>maxlen){
			maxlen=dp[i];
			res=cnt[i];
		}
		else if(dp[i]==maxlen)
			res+=cnt[i];
	}
	return res;
}
```

