### 最长回文子序列

给你一个字符串 s ，找出其中最长的回文子序列，并返回该序列的长度。

子序列定义为：不改变剩余字符顺序的情况下，删除某些字符或者不删除任何字符形成的一个序列。

**示例 1：**

```
输入：s = "bbbab"
输出：4
解释：一个可能的最长回文子序列为 "bbbb" 。
```



##### 动态规划

设dp[i] [j]表示i到j范围内最长的回文子序列，则：
$$
dp[i][j]=\begin{cases}
dp[i+1][j-1]+2,s[i]==s[j]\\
max(dp[i+1][j],dp[i][j-1])
\end{cases}
$$

```c++
int longestPalindromeSubseq(string s){
	int n=s.size();
	vector<vector<int>> dp(n,vector<int>(n,0));
	for(int i=n-1;i>=0;i--){
		char ch1=s[i];
		dp[i][i]=1;
		for(int j=i+1;j<n;j++){
			char ch2=s[j];
			if(ch1==ch2)
				dp[i][j]=dp[i+1][j-1]+2;
			else
				dp[i][j]=max(dp[i+1][j],dp[i][j-1]);
		}
	}
	return dp[0][n-1];
}
```

