### 最长公共子序列：

设dp[i] [j]的含义为：字符串s在0～i范围内与字符串t在0～j范围内的最长公共子序列，当i=0或者j=0时，公共子序列大小都为0，则dp[i] [0]及dp[0] [j]都为0。则对于任意dp[i] [j]有：
$$
dp[i][j]=
\begin{cases}
dp[i-1][j-1]+1,s[i-1]=t[j-1]\\
max(dp[i-1][j],dp[i][j-1]),s[i-1]!=t[j-1]
\end{cases}
$$


```c++
int longestCommonSubsequence(string text1,string tetx2){
	int m=text1.size(),n=tetx2.size();
	vector<vector<int>> dp(m+1,vector<int>(n+1));
	for(int i=1;i<=m;i++){
		char ch1=text1[i-1];
		for(int j=1;j<=n;j++){
			char ch2=tetx2[j-1];
			if(ch1==ch2)
				dp[i][j]=dp[i-1][j-1]+1;
			else
				dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
		}
	}
	return dp[m][n];
}
```

