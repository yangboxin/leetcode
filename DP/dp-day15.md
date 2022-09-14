### 不同路径 (I)、II

一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为 “Start” ）。

机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为 “Finish”）。

现在考虑网格中有障碍物。那么从左上角到右下角将会有多少条不同的路径？

网格中的障碍物和空位置分别用 1 和 0 来表示。



### 动态规划

对于第一行和第一列的格子：

若某一位置存在障碍物，则这个位置之后的所有格子都不可能到达。

对于第一行第一列以外的每一个格子，有四种可能的状态：

1. 左边的格子有障碍物，上方也有障碍物，则这个格子不可能到达。
2. 左边的格子有障碍物，上方的格子没有障碍物，则可以由上方的格子向下走一步到达。
3. 左边的格子没有障碍物，上方的格子有障碍物，则可以由左边的格子向右走一步到达。
4. 左边和上方的格子都没有障碍物，则可以由左边的格子向右走一步到达或者上方的格子向下走一步到达。

可以得到状态转移方程
$$
dp[i][j]=\begin{cases}
0,obstacle[i-1][j]==1\ and\ obstacle[i][j-1]==1\\
dp[i-1][j]+0,obstacle[i][j-1]==1\\
0+dp[i][j-1],obstacle[i-1][j]==1\\
dp[i-1][j]+dp[i][j-1],else
\end{cases}
$$




```c++
int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid){
	int m=obstacleGrid.size(),n=obstacleGrid[0].size();
	if(obstacleGrid[m-1][n-1]==1 || obstacleGrid[0][0]==1)
		return 0;
	int dp[m][n];
	for(int i=0;i<m;i++){
		if(i>0 && obstacleGrid[i][0]==0)
			dp[i][0]=dp[i-1][0];
		else if(obstacleGrid[i][0]==1)
			dp[i][0]=0;
		else if(i==0)
			dp[0][0]=1;
	}
	for(int j=0;j<n;j++){
		if(j>0 && obstacleGrid[0][j]==0)
			dp[0][j]=dp[0][j-1];
		else if(obstacleGrid[0][j]==1)
			dp[0][j]=0;
	}
	for(int i=1;i<m;i++){
		for(int j=1;j<n;j++){
			int tmp1=obstacleGrid[i-1][j]==1?0:dp[i-1][j];
			int tmp2=obstacleGrid[i][j-1]==1?0:dp[i][j-1];
			dp[i][j]=tmp1+tmp2;
		}
	}
	return dp[m-1][n-1];
}
```

