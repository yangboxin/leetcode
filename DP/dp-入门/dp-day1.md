### lc-509,lc-1137

「斐波那契数」和「泰波那契数」的第n个，可以使用相同的思路进行动态规划，公式都类似如下：
$$
f(n)=f(n-1)+f(n-2)
$$
同时可以使用滚动数组的思路对状态的存储进行优化

模版：

```c++
int nthFibonacci(int n){
	if(n==0||n==1)
		return n==0?0:1;
	int mod=1e9+7;
	int last=1,llast=0;
	int res=0;
	for(int i=2;i<=n;i++){
		res=(last+llast)%mod;
		llast=last;
		last=res;
	}
	return res;
}
```

