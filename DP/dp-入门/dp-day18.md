### 最长递增子序列问题

定义dp[i]的含义为：以下标i结尾的子数组中最长的递增子序列的大小，则有：
$$
dp[i]=max(dp[i],dp[j]+1)，0\leq j<i
$$

```c++
int lengthOfLIS(vector<int>& nums){
	int n=nums.size();
	vector<int> dp(n,0);
	for(int i=0;i<n;i++){
		dp[i]=1;
		for(int j=0;j<i;j++){
			if(nums[i]<nums[j])
				dp[i]=max(dp[i],dp[j]+1);
		}
	}
	return *max_element(dp.begin(), dp.end());
}
```

