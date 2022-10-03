#### 矩阵中最长的连续1线段

给定一个 `m x n` 的二进制矩阵 `mat` ，返回矩阵中最长的连续1线段。

这条线段可以是水平的、垂直的、对角线的或者反对角线的。



##### 动态规划

根据题意，除了最外层的一圈外，每一个位置的最长连续1线段可以由左侧（水平）、上方（垂直）、左斜上方（对角线）和右斜上方（反对角线）转移而来。

但如果因此就将dp数组设置为一个二维数组，dp[i] [j]表示i，j处最长的连续1线段，则会由于多个状态转移造成重复的计算，使得结果不准确。

需要对水平、垂直、对角线、反对角线四个方向分别设立动态规划数组horizontal、vertical、diagonal、antidiagonal，并且有：
$$
horizontal[i][j]=mat[i][j]==1?horizontal[i][j-1]+1:0
\\
vertical[i][j]=mat[i][j]==1?horizontal[i-1][j]+1:0\\
diagonal[i][j]=mat[i][j]==1?diagonal[i-1][j-1]+1:0\\
antidiagonal[i][j]=mat[i][j]==1?antidiagonal[i-1][j+1]+1:0
$$
同时注意到每个状态只与上一行（或本行有关），可以用滚动数组优化空间



```c++
class Solution {
public:
    int longestLine(vector<vector<int>>& M) {
        if (M.empty())
            return 0;
        int ans = 0;
        int* horizontal = new int[M[0].size()];
        int* vertical = new int[M[0].size()];
        int* diagonal = new int[M[0].size()];
        int* antidiagonal = new int[M[0].size()];
        for (int i = 0; i != M.size(); ++i) {
            int* vertical_new = new int[M[0].size()];
            int* diagonal_new = new int[M[0].size()];
            int* antidiagonal_new = new int[M[0].size()];
            for (int j = 0; j != M[0].size(); ++j) {
                if (M[i][j] == 0) {
                    horizontal[j] = 0;
                    vertical_new[j] = 0;
                    diagonal_new[j] = 0;
                    antidiagonal_new[j] = 0;
                } else {
                    horizontal[j] = j > 0 ? horizontal[j - 1] + 1 : 1;
                    vertical_new[j] = i > 0 ? vertical[j] + 1 : 1;
                    diagonal_new[j] = i > 0 && j > 0 ? diagonal[j - 1] + 1 : 1;
                    antidiagonal_new[j] = i > 0 && j < M[0].size() - 1 ? antidiagonal[j + 1] + 1 : 1;
                    ans = max(ans, horizontal[j]);
                    ans = max(ans, vertical_new[j]);
                    ans = max(ans, diagonal_new[j]);
                    ans = max(ans, antidiagonal_new[j]);
                }
            }
            vertical = move(vertical_new);
            diagonal = move(diagonal_new);
            antidiagonal = move(antidiagonal_new);
        }
        return ans;
    }
};
```

