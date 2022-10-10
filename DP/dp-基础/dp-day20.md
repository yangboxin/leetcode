### 完全平方数

给你一个整数 n ，返回 和为 n 的完全平方数的最少数量 。

完全平方数 是一个整数，其值等于另一个整数的平方；换句话说，其值等于一个整数自乘的积。例如，1、4、9 和 16 都是完全平方数，而 3 和 11 不是。



##### 动态规划

可能的数字的范围为[1,n^0.5],枚举这些数字j，并计算剩下的i-j^2的可能性



```c++
int numSquares(int n){
	vector<int> dp(n+1);
	for(int i=1;i<=n;i++){
		int minn=0x7fffffff;
		for(int j=1;j*j<=i;j++){
			minn=min(minn,dp[i-j*j]);
		}
		dp[i]=minn+1;
	}
	return dp[n];
}
```