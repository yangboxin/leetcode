两个买卖股票题目的变种，变种1:

### lc-309

给定一个整数数组prices，其中第  prices[i] 表示第 i 天的股票价格 。

设计一个算法计算出最大利润。在满足以下约束条件下，你可以尽可能地完成更多的交易（多次买卖一支股票）:

卖出股票后，你无法在第二天买入股票 (即冷冻期为 1 天)。
注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。

 

示例 1:

输入: prices = [1,2,3,0,2]
输出: 3 
解释: 对应的交易状态为: [买入, 卖出, 冷冻期, 买入, 卖出]



大体思路还是如此类题型一般，分别计算当天持有股票和卖出票带来的收益，不过需要加入一个冻结状态，这个状态只能由卖出转移而来，只能转移到买入。



```c++
int maxProfit(vector<int>& prices){
	int n=prices.size();
	int f0=-prices[0];//买入
	int f1=0;//卖出
	int f2=0;//冻结
	for(int i=1;i<n;i++){
		int newf0=max(f0,f2-prices[i]);
		int newf1=f0+prices[i];
		int newf2=max(f1,f2);
		f0=newf0;
		f1=newf1;
		f2=newf2;
	}
	return max(f1,f2);
}
```





### lc-714

给定一个整数数组 prices，其中 prices[i]表示第 i 天的股票价格 ；整数 fee 代表了交易股票的手续费用。

你可以无限次地完成交易，但是你每笔交易都需要付手续费。如果你已经购买了一个股票，在卖出它之前你就不能再继续购买股票了。

返回获得利润的最大值。

注意：这里的一笔交易指买入持有并卖出股票的整个过程，每笔交易你只需要为支付一次手续费。

 

示例 1：

输入：prices = [1, 3, 2, 8, 4, 9], fee = 2
输出：8
解释：能够达到的最大利润:  
在此处买入 prices[0] = 1
在此处卖出 prices[3] = 8
在此处买入 prices[4] = 4
在此处卖出 prices[5] = 9
总利润: ((8 - 1) - 2) + ((9 - 4) - 2) = 8



思路同此类题，每次计算卖出收益时减去手续费。



```c++
int maxProfit(vector<int>& prices,int fee){
	int n=prices.size();
	int sell=0,buy=-prices[0];
	for(int i=1;i<n;i++){
		tie(sell,buy)=pair(max(sell,buy+prices[i]-fee),max(buy,sell-prices[i]));
	}
	return sell;
}
```

