### 最长公共子序列

给定两个字符串 text1 和 text2，返回这两个字符串的最长 公共子序列 的长度。如果不存在 公共子序列 ，返回 0 。

一个字符串的 子序列 是指这样一个新的字符串：它是由原字符串在不改变字符的相对顺序的情况下删除某些字符（也可以不删除任何字符）后组成的新字符串。

例如，"ace" 是 "abcde" 的子序列，但 "aec" 不是 "abcde" 的子序列。
两个字符串的 公共子序列 是这两个字符串所共同拥有的子序列。



##### 动态规划

设dp[i] [j]为text1中[0,i]与text2中[0,j]内的最长公共子序列长度。

则：
$$
dp[i][j]=
\begin{cases} dp[i-1][j-1]+1,text1[i-1]=text2[j-1]\\
max(dp[i-1][j],dp[i][j-1])
\end{cases}
$$

```c++
class Solution {
public:
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
};
```

