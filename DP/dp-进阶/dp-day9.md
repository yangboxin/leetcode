### 验证回文字符串III

给出一个字符串 `s` 和一个整数 `k`，若这个字符串是不是一个「k **回文** 」，则返回 `true` 。

如果可以通过从字符串中删去最多 `k` 个字符将其转换为回文，那么这个字符串就是一个「**k** **回文** 」。



##### 动态规划求最长回文子序列

求最长回文子序列maxk，比较maxk与k的大小，若n-maxk<=k,则是一个k回文



```c++
class Solution{
public:
	bool isValidPalindrome(string s,int k){
		int n=s.size();
		int dp[n][n];
		memset(dp,0,sizeof(dp));
		for(int i=n-1;i>=0;i--){
			dp[i][i]=1;
			for(int j=i+1;j<n;j++){
				if(s[i]==s[j])
					dp[i][j]=max(dp[i][j],dp[i+1][j-1])+2;
				else
					dp[i][j]=max(dp[i+1][j],dp[i][j-1]);
				if(n-dp[i][j] <= k)
					return true;
			}
		}
		return false;
	}
};
```

