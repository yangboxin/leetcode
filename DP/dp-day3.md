你是一个专业的小偷，计划偷窃沿街的房屋。每间房内都藏有一定的现金，影响你偷窃的唯一制约因素就是相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。

给定一个代表每个房屋存放金额的非负整数数组，计算你 不触动警报装置的情况下 ，一夜之内能够偷窃到的最高金额。





打家劫舍问题：相邻的数字不可都被选择，可以推出一个普适性的状态转移方程：
$$
f(n)=max(f(n-2)+nums[i],f(n-1))
$$
*lc-198,213,740*都是此类问题，213中的变化是「头尾两个元素是相连的」，则此时答案存在两种状态，一种是选择下标为0的元素，则n-1不可选择，在[0,n-2]内做上述dp；另一种是选择下标为1的元素，则下标0不可选择，在[0,n-1]上做dp。



#### lc-740

给你一个整数数组 nums ，你可以对它进行一些操作。

每次操作中，选择任意一个 nums[i] ，删除它并获得 nums[i] 的点数。之后，你必须删除 所有 等于 nums[i] - 1 和 nums[i] + 1 的元素。

开始你拥有 0 个点数。返回你能通过这些操作获得的最大点数。



740则是把打家劫舍问题隐藏在条件中,{删除 所有 等于 nums[i] - 1 和 nums[i] + 1 的元素}这一条件可以等价为「相邻的房屋不可同时偷窃」这一条件，只需计算nums中的最大值maxval，建立int tmp[maxval+1]数组，则原问题就可以转化为在tmp中做「打家劫舍」问题。



```c++
int dp(vector<int>& sums){
	int n=sums.size();
	int llast=sums[0];
	int last=max(sums[0],sums[1]);
	int res=last;
	for(int i=2;i<n;i++){
		res=max(llast+sums[i],last);
		llast=last;
		last=res;
	}
	return res;
}
int deleteAndEarn(vector<int>>& nums){
	int n=nums.size();
	if(n==1)
		return nums[0];
	int maxelem=*max_element(nums.begin(), nums.end());
	vector<int> sums(maxelem+1);
	for(auto& sum:sums)
		sum+=sum;
	return dp(sums);
}
```

