跳跃游戏类型，实际上存在贪心算法的解法，并且其正确性可以被验证



```c++
int jump(vector<int>& nums){
	int n=nums.size();
	int end=0,res=0,maxbound=0;
	for(int i=0;i<n-1;i++){
		maxbound=max(maxbound,i+nums[i]);
		if(i==end){
			res++;
			end=maxbound;
		}
	}
	return res;
}
```