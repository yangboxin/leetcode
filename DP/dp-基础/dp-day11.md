### 回文子串

给你一个字符串 s ，请你统计并返回这个字符串中 回文子串 的数目。

回文字符串 是正着读和倒过来读一样的字符串。

子字符串 是字符串中的由连续字符组成的一个序列。

具有不同开始位置或结束位置的子串，即使是由相同的字符组成，也会被视作不同的子串。

 



##### 动态规划

设dp[i] [j]表示s从i到j是否为回文子串，是则为1，否则为0.

- 当s[i]与s[j]不相等时，肯定不是回文子串即dp[i] [j]=0.
- 当s[i]与s[j]相等时，根据i和j的情况：

1. ​	i==j，dp[i] [j]=1.
2. i与j相差为1，dp[i] [j]=1
3. i于j相差大于1时，说明区间内字符数大于等于三个，可以根据[i+1,j-1]是否是回文串来判断

```c++
class Solution {
public:
   int countSubstrings(string s) {
      int cnt = 0;
      int lenth = s.size();
      vector<vector<int>> lps(lenth,vector<int>(lenth));
      for (int i = 0; i < lenth; i++)
          for (int j = 0; j <= i; j++)
              if (i == j)
              {
                  cnt++;
                  lps[i][j] = 1;
              }
              else if (s[i] == s[j])
              {
                  if (i - j == 1)
                  {
                      cnt++;
                      lps[i][j] = 1;
                  }
                  else if (lps[i - 1][j + 1]==1)
                  {
                      cnt++;
                      lps[i][j] = 1;
                  }
              }
      return cnt;
  }
};
```

