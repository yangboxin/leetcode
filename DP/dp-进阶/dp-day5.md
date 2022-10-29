### 不同的子序列

给定一个字符串 `s` 和一个字符串 `t` ，计算在 `s` 的子序列中 `t` 出现的个数。

字符串的一个 **子序列** 是指，通过删除一些（也可以不删除）字符且不干扰剩余字符相对位置所组成的新字符串。（例如，`"ACE"` 是 `"ABCDE"` 的一个子序列，而 `"AEC"` 不是）

题目数据保证答案符合 32 位带符号整数范围。

**示例 1：**

```
输入：s = "rabbbit", t = "rabbit"
输出：3
解释：
如下图所示, 有 3 种可以从 s 中得到 "rabbit" 的方案。
rabbbit
rabbbit
rabbbit
```



##### 动态规划

定义dp[i] [j],表示在s[i:-1]中t[j:-1]出现的次数，s大小为n，t大小为m，根据定义有：当i=n时，空字符串没有子序列，所以dp[n] [j]=0;当j=m时，空字符串是任何字符串的子序列，所以dp[i] [m]=1.

对于任意的i，j：
$$
dp[i][j]=\begin{cases}dp[i+1][j+1]+dp[i+1][j],s[i]==t[j]\\
dp[i+1][j],s[i]\ne t[j]
\end{cases}
$$
当s[i]=t[j]时，可以选取当前的字符，即dp[i+1] [j+1]；也可以跳过当前字符，即dp[i+1] [j].

当s[i]!=t[j]时，只能跳过当前字符,dp[i+1] [j].



```c++
class Solution{
public:
	int numDistinct(string s,string t){
		int n=s.size(),m=t.size();
        if(n<m)
            return 0;
		vector<vector<unsigned int>> dp(n+1,vector<unsigned int>(m+1,0));
		for(int i=0;i<=n;i++)
			dp[i][m]=1;
		for(int i=n-1;i>=0;i--){
			char si=s[i];
			for(int j=m-1;j>=0;j--){
				if(si==t[j])
					dp[i][j]=dp[i+1][j+1]+dp[i+1][j];
				else
					dp[i][j]=dp[i+1][j];
			}
		}
		return dp[0][0];
	}
};
```

