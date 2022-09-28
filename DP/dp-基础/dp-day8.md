### 两个字符串的最小ASCII删除和

给定两个字符串s1 和 s2，返回 使两个字符串相等所需删除字符的 ASCII 值的最小和 。

 

```
示例 1:

输入: s1 = "sea", s2 = "eat"
输出: 231
解释: 在 "sea" 中删除 "s" 并将 "s" 的值(115)加入总和。
在 "eat" 中删除 "t" 并将 116 加入总和。
结束时，两个字符串相等，115 + 116 = 231 就是符合条件的最小和。
```



##### 找最长公共子序列

```c++
int maxAsciiSum(string s1,string s2){
	int n=s1.size(),m=s2.size();
	vector<vector<int>> dp(n+1,vector<int>(m+1,0));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(s1[i-1]==s2[j-1]){
				dp[i][j]=dp[i-1][j-1]+s1[i-1];
			}
			else{
				dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
			}
		}
	}
	return dp[n][m];
}
int minimumDeleteSum(string s1,string s2){
	return accumulate(s1.begin(), s1.end(),0)+accumulate(s2.begin(), s2.end(),0)-2*maxAsciiSum(s1,s2);
}
```

