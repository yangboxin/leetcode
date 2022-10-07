### 出界的路径数

给你一个大小为 m x n 的网格和一个球。球的起始坐标为 [startRow, startColumn] 。你可以将球移到在四个方向上相邻的单元格内（可以穿过网格边界到达网格之外）。你 最多 可以移动 maxMove 次球。

给你五个整数 m、n、maxMove、startRow 以及 startColumn ，找出并返回可以将球移出边界的路径数量。因为答案可能非常大，返回对 109 + 7 取余 后的结果。



##### 动态规划

定义dp[i] [j] [k]表示球移动i次之后位于坐标(j,k)的路径数量。当i=0时，球一定位于起始坐标(startRow,startColumn)，因此动态规划的边界情况是：dp[0] [startRow] [startColumn]=1,当(j,k)!=(startRow,startColumn)时有dp[0] [j] [k]=0.

如果球移动了i次之后位于坐标(j,k)，且i<maxMove,0<=j<m,0<=k<n,则移动第i+1次之后，球一定位于和坐标(j,k)相邻的一个坐标，记为(j',k').

- 当0<=j'<m且0<=k'<n时，球在移动i+1次之后没有出界，将dp[i] [j] [k]的值加到dp[i+1] [j'] [k']
- 否则，球在第i+1次移动之后出界，将dp[i] [j] [k]的值加到出界的路径数

由于最多可以移动的次数是maxMove，因此遍历0<=i<maxMove,根据dp[i] [] []

计算dp[i+1] [] []的值以及出界的路径数，即可得到最多移动maxMove次的情况下的出界的路径数。

同时可以注意到，每次移动只与上一次移动有关，可以优化空间复杂度。

```c++
int mod=1e9+7;

int findPaths(int m,int n,int maxMove,int startRow,int startColumn){
	vector<vector<int>> directions={{0,1},{0,-1},{1,0},{-1,0}};
	int outCounts=0;
	vector<vector<int>> dp(m,vector<int>(n));
	dp[startRow][startColumn]=1;
	for(int i=0;i<maxMove;i++){
		vector<vector<int>> dpNew(m,vector<int>(n));
		for(int j=0;j<m;j++){
			for(int k=0;k<n;k++){
				int count=dp[j][k];
				if(count>0){
					for(auto& direction:directions){
						int j1=j+direction[0],k1=k+direction[1];
						if(j1>=0&&j1<m&&k1>=0&&k1<n){
							dpNew[j1][k1]=(dpNew[j1][k1]+count)%mod;
						}
						else{
							outCounts=(count+outCounts)%mod;
						}
					}
				}
			}
		}
		dp=dpNew;
	}
	return outCounts;
}
```

