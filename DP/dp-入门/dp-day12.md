### 杨辉三角

设置一个二维数组yhtri，yhtri[i] [j]代表杨辉三角形中第i行，第j列上的元素，则有：
$$
ygtri[i][j]=yhtri[i-1][j-1]+yhtri[i-1][j],1\leq j<i
$$
要求整个杨辉三角数组：

```c++
vector<vector<int>> generate(int numRows){
	vector<vector<int>> yhtri(numRows);
	for(int i=0;i<numRows;i++){
		yhtri[i].resize(i+1);
		yhtri[i][0]=yhtri[i][i]=1;
		for(int j=1;j<i;j++)
			yhtri[i][j]=yhtri[i-1][j-1]+yhtri[i-1][j];
	}
	return yhtri;
}
```

