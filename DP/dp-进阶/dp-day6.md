### 用最少数量的箭引爆气球lc-452

有一些球形气球贴在一堵用 XY 平面表示的墙面上。墙面上的气球记录在整数数组 `points` ，其中`points[i] = [xstart, xend]` 表示水平直径在 `xstart` 和 `xend`之间的气球。你不知道气球的确切 y 坐标。

一支弓箭可以沿着 x 轴从不同点 **完全垂直** 地射出。在坐标 `x` 处射出一支箭，若有一个气球的直径的开始和结束坐标为 `x``start`，`x``end`， 且满足  `xstart ≤ x ≤ x``end`，则该气球会被 **引爆** 。可以射出的弓箭的数量 **没有限制** 。 弓箭一旦被射出之后，可以无限地前进。

给你一个数组 `points` ，*返回引爆所有气球所必须射出的 **最小** 弓箭数* 。

 

**示例 1：**

```
输入：points = [[10,16],[2,8],[1,6],[7,12]]
输出：2
解释：气球可以用2支箭来爆破:
-在x = 6处射出箭，击破气球[2,8]和[1,6]。
-在x = 11处发射箭，击破气球[10,16]和[7,12]。
```



##### 排序+贪心

类似于lc-435无重叠区间，按照右端点升序排序，再选择尽量能多满足条件的区间，如在435中应该选择右端点尽量小的区间以使得后面更多的区间能被放入，而在本题中则应该选择能「囊括」进更多区间的位置射箭以使得射出的弓箭数最小。



```c++
class Solution{
public:
	int findMinArrowShots(vector<vector<int>>& points){
		int n=points.size();
		sort(points.begin(), points.end(),[](auto& a,auto& b){
			return a[1]<b[1];
		});
		int res=1;
		int pos=points[0][1];
		for(int i=1;i<n;i++){
			if(points[i][0]>pos){
				pos=points[i][1];
				res++;
			}
		}
		return res;
	}
};
```

