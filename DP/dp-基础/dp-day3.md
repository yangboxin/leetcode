### 粉刷房子问题

假如有一排房子共有 n 幢，每个房子可以被粉刷成 k 种颜色中的一种。房子粉刷成不同颜色的花费成本也是不同的。你需要粉刷所有的房子并且使其相邻的两个房子颜色不能相同。

每个房子粉刷成不同颜色的花费以一个 n x k 的矩阵表示。

例如，costs[0] [0] 表示第 0 幢房子粉刷成 0 号颜色的成本；costs[1] [2] 表示第 1 幢房子粉刷成 2 号颜色的成本，以此类推。
返回 粉刷完所有房子的最低成本 。

 

示例 1：

```
输入: costs = [[1,5,3],[2,9,4]]
输出: 5
解释: 
将房子 0 刷成 0 号颜色，房子 1 刷成 2 号颜色。花费: 1 + 4 = 5; 
或者将 房子 0 刷成 2 号颜色，房子 1 刷成 0 号颜色。花费: 3 + 2 = 5. 
```



##### 动态规划

从1号房子开始：对于每个i房子有，其颜色选择不能与i-1的房子颜色相同，并且应该选择cost尽可能小的颜色。我们设dp[i] [j]代表对于第i个房子选择第j个颜色带来的cost，且：
$$
dp[i][j]=min_{1\leq t<k,t!=j}(dp[i-1][t])+costs[i][j]
$$
最终dp[n-1]中的最小值就是答案，同时注意到每次状态只与上一个房子有关，可以使用「滚动数组」优化空间。在遍历每个房子的颜色选择时，还需要重复计算上一排房子的最小值，可以对每个房子维护一个最小值和一个次小值（避免与当前颜色重复），每次直接使用即可，可以将原有的O(n*k^2)的复杂度优化到O(nk)。



```c++
int minCostII(vector<vector<int>>& costs){
	int n=costs.size(),k=costs[0].size();
	vector<int> dp(k);
	int first=INT_MAX,second=INT_MAX;
	for(int j=0;j<k;j++){
		dp[j]=costs[0][j];
		if(dp[j]<first){
			second=first;
			first=dp[j];
		}
		else if(dp[j]<second)
			second=dp[j];
	}
	for(int i=1;i<n;i++){
		vector<int> dpNew(k);
		int firstNew=INT_MAX,secondNew=INT_MAX;
		for(int j=0;j<k;j++){
			int prevMin=dp[j]!=first?first:second;
			dpNew[j]=prevMin+costs[i][j];
			if(dpNew[j]<firstNew){
				secondNew=firstNew;
				firstNew=dpNew[j];
			}
			else if(dpNew[j]<secondNew)
				secondNew=dpNew[j];
		}
		dp=move(dpNew);
		first=firstNew;
		second=secondNew;
	}
	return *min_element(dp.begin(), dp.end());
}
```

