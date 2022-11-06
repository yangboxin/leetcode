### 4键键盘

假设你有一个特殊的键盘包含下面的按键：

- `A`：在屏幕上打印一个 `'A'`。
- `Ctrl-A`：选中整个屏幕。
- `Ctrl-C`：复制选中区域到缓冲区。
- `Ctrl-V`：将缓冲区内容输出到上次输入的结束位置，并显示在屏幕上。

现在，*你可以 **最多** 按键 `n` 次（使用上述四种按键），返回屏幕上最多可以显示 `'A'` 的个数* 。

 

##### 动态规划

```c++
class Solution {
public:
    int maxA(int N) {
        int dp[N+1];
        memset(dp, 0, sizeof(dp));

        for(int i = 1; i <= N; i++) {
            dp[i] = dp[i-1] + 1;
            for(int j = 2; j < i; j++) {
                dp[i] = max(dp[i], dp[j-2] * (i-j+1));
            }
        }
        return dp[N];
    }
};
```

