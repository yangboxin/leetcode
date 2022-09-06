买卖股票问题，由简单到困难衍生出很多类型，相关的题目有：

- https://leetcode.cn/problems/best-time-to-buy-and-sell-stock/
- https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-ii/
- https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-iii/
- https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-iv/
- https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-with-cooldown/
- https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/

但其最核心的思想都是相通的，分别计算当日卖出和买入状态下的最大收益，最后得到的卖出收益就是答案。

对于最为复杂的188题https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-iv/，限制买卖的次数不大于k，需要分别计算「买入」的状态和「卖出」的状态。

使用buy[i] [j]表示对于prices[0...i]中的价格，进行恰好j笔交易并且当前手上持有一支股票这种情况的最大利润；用sell[i] [j]表示恰好进行j笔交易后，手上不持有股票这种情况下的最大利润。

则有状态转移方程：
$$
buy[i][j]=max(buy[i-1][j],sell[i-1][j]-prices[i])\\
sell[i][j]=max(sell[i-1][j],buy[i-1][j-1]+prices[i])
$$
对于buy[i] [j]来说，考虑股票是否在第i天买入，若选择买入则第i-1天必须处于卖出状态sell[i-1] [j]并且买入的收益为-prices[i]；若在第i天不选择买入，则维持上一次买入的状态buy[i-1] [j]。

对于sell[i] [j]，考虑股票是否在第i天卖出，若在第i天卖出，则第i-1天必须处于持有状态buy[i-1] [j-1]，卖出股票的收益为prices[i]；若在第i天不卖出，则保持之前卖出后的状态sell[i-1] [j]。

在更新完这两个数组之后，最后卖出的收益一定大于持有，但并不是交易次数越多越好，所以答案是sell[0...n] [0...k]中的最大值。

可以注意到，每一个状态i都只与前一个状态i-1有关，可以使用「滚动数组」的思想来优化空间，将两维的状态数组优化为一维。



```c++
int maxProfit(int k,vector<int>& prices){
	if(prices.empty())
		return 0;
	int n=prices.size();
	k=min(k,n/2);
	vector<int> buy(k+1);
	vector<int> sell(k+1);
	int res=0;
	buy[0]=-prices[i];
	sell[0]=0;
	for(int i=1;i<=k;i++)
		buy[i]=sell[i]=INT_MIN/2;

	for(int i=1;i<n;i++){
		buy[0]=max(buy[0],sell[0]-prices[i]);
		for(int j=1;j<=k;j++){
			buy[j]=max(buy[j],sell[j]-prices[i]);
			sell[j]=max(sell[j],buy[j-1]+prices[i]);
			res=max(sell[j],res);
		}
	}
	return res;
}
```

