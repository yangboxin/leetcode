### 屏幕可显示的句子的数量

给你一个 `rows x cols` 的屏幕和一个用 **非空** 的单词列表组成的句子，请你计算出给定句子可以在屏幕上完整显示的次数。

**注意：**

1. 一个单词不能拆分成两行。
2. 单词在句子中的顺序必须保持不变。
3. **在一行中** 的两个连续单词必须用一个空格符分隔。
4. 句子中的单词总量不会超过 100。
5. 每个单词的长度大于 0 且不会超过 10。
6. 1 ≤ `rows`, `cols` ≤ 20,000.

 

**示例 1：**

```
输入：
rows = 2, cols = 8, 句子 sentence = ["hello", "world"]

输出：
1

解释：
hello---
world---

字符 '-' 表示屏幕上的一个空白位置。
```



##### 动态规划

动态规划解法 比较奇葩 关键是设计memory结构 抓住本题词数和词长都很小但rows cols很长的特点 见代码注释



```c++
class Solution {
public:
    int wordsTyping(vector<string>& sentence, int rows, int cols) {
	// 从第 i 个词开始 这一行能放下几遍句子
	vector<int> dp(sentence.size(), 0);
	// 从第 i 个词开始 放下dp[i]遍句子后 变为第几个词
	vector<int> next(sentence.size(), 0);

	for (int i = 0; i < sentence.size(); ++i) {
	    int count = 0;
	    int ptr = i;
	    int cur = cols;
	    while (cur >= (int)sentence[ptr].size()) {
		cur -= sentence[ptr].size() + 1;
		++ptr;
		if (ptr == sentence.size()) {
		    ++count;
		    ptr = 0;
		}
	    }
	    dp[i] = count;
	    next[i] = ptr;
	}

	int count = 0;
	int cur = 0;
	for (int i = 0; i < rows; ++i) {
	    count += dp[cur];
	    cur = next[cur];
	}
	return count;
    }
};

```

