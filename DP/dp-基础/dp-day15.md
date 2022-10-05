### 因子的组合	

整数可以被看作是其因子的乘积。

例如：

8 = 2 x 2 x 2;
  = 2 x 4.
请实现一个函数，该函数接收一个整数 n 并返回该整数所有的因子组合。

注意：

你可以假定 n 为永远为正数。
因子必须大于 1 并且小于 n。
示例 1：

```
输入: 12
输出:
[
  [2, 6],
  [2, 2, 3],
  [3, 4]
]
```



##### 回溯

```c++
vector<vector<int>> res;
vector<int> tmp;
void dfs(int num,int l){
	if(!tmp.empty()){
		res.push_back(tmp);
		res.back().push_back(num);
	}
	for(int i=l;i<=int(pow(num,0.5));i++){
		if(num%i==0){
			tmp.push_back(i);
			dfs(num/i,i);
			tmp.pop_back();
		}
	}
}
vector<vector<int>> getFactors(int n){
	dfs(n,2);
	return res;
}
```

