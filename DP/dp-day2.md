### lc-70,lc-746

爬楼梯类型题目，跟斐波那契数列其实异曲同工，dp[i]的意义是到达第i个阶梯所需要的最小爬台阶次数，则根据题目可以由初始状态推出爬到顶部所需的最小次数。以746题为例，此题还带有「向上爬需要支付费用」这一条件，则状态转移方程为：
$$
f(n)=max(f(n-1)+cost[n-1],f(n-2)+cost[n-2])
$$
同时也能使用「滚动数组」来优化空间，以下给出此类题型的模版：

```c++
int minCostClimbingStairs(vector<int>& cost){
	int n=cost.size();
	int last=0,llast=0;//dp[i-1],dp[i-2]
	int res=0;//dp[i]
	for(int i=2;i<=n;i++){
		res=max(last+cost[i-1],llast+cost[i-2]);
		llast=last;
		last=res;
	}
	return res;
}
```

