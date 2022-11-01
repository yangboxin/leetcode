### 最短公共超序列

给出两个字符串 `str1` 和 `str2`，返回同时以 `str1` 和 `str2` 作为子序列的最短字符串。如果答案不止一个，则可以返回满足条件的任意一个答案。

（如果从字符串 T 中删除一些字符（也可能不删除，并且选出的这些字符可以位于 T 中的 **任意位置**），可以得到字符串 S，那么 S 就是 T 的子序列）

 

**示例：**

```
输入：str1 = "abac", str2 = "cab"
输出："cabac"
解释：
str1 = "abac" 是 "cabac" 的一个子串，因为我们可以删去 "cabac" 的第一个 "c"得到 "abac"。 
str2 = "cab" 是 "cabac" 的一个子串，因为我们可以删去 "cabac" 末尾的 "ac" 得到 "cab"。
最终我们给出的答案是满足上述属性的最短字符串。
```



https://leetcode.cn/problems/shortest-common-supersequence/solutions/1621954/c-by-answerer-ppss/?languageTags=cpp

求两者的LCSLCSLCS这个题是模板题，而且状态转移很简单，这里就不赘述了 可以看最长公共子序列这个题 这个题的思路大致为：

求出两者最短的LCSLCSLCS
按照这个LCSLCSLCS序列来填充字符（因为LCSLCSLCS对应的字符只填充一次，其余填充两次）
接下来就是求出这个序列，我们知道，DPDPDP是没有后效性的，所以需要结合状态定义倒推来做（正推会出现问题。因为我们当前长度的字符如果加入LCSLCSLCS不一定是最优解，举个例子，长度为555的LCSLCSLCS和长度为777的LCSLCSLCS有可能长度为555的先被匹配，这个时候就不能往下走找到6..76..76..7了 并且，由于状态定义是f(i,j)f(i, j)f(i,j)表示考虑str1str1str1中前iii个字符以及考虑str2str2str2中jjj个字符的最长公共子序列的长度，它并不一定是当前字符产生的贡献，我们需要判断是否有a[i]==b[j]a[i] == b[j]a[i]==b[j]来判断是否构成 于是这部分判断逻辑为：



```c++
class Solution {
    //首先求出LCS双方对应的最短串，然后往中间填充
    int f[1010][1010];
    string LCS;
public:
    string shortestCommonSupersequence(string & a, string & b) {
        int n = a.size(), m = b.size();
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= m; j++){
                if(a[i - 1] == b[j - 1]) {
                    f[i][j] = f[i - 1][j - 1] + 1;
                }
                else {
                    f[i][j] = max(f[i][j - 1], f[i - 1][j]);
                }
            }
        }
        //通过DP的信息倒推得到这个序列
        int i = n - 1,j =  m - 1;
        while(i >= 0 && j >= 0){
            if(a[i] == b[j]) LCS += a[i], i--, j--;
            else {
                if(f[i][j + 1] > f[i + 1][j]) i--;
                else j--;
            }
        }
        string ans;
        i = 0, j = 0;
        while(LCS.size()){
            while(i < n && a[i] != LCS.back()) ans += a[i++];
            while(j < m && b[j] != LCS.back()) ans += b[j++];
            ans += LCS.back();
            LCS.pop_back();
            i++, j++;
        }
        while(i < n) ans += a[i++];
        while(j < m) ans += b[j++];
        return ans;
    }
};

```

