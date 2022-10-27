### 规划兼职工作

你打算利用空闲时间来做兼职工作赚些零花钱。

这里有 `n` 份兼职工作，每份工作预计从 `startTime[i]` 开始到 `endTime[i]` 结束，报酬为 `profit[i]`。

给你一份兼职工作表，包含开始时间 `startTime`，结束时间 `endTime` 和预计报酬 `profit` 三个数组，请你计算并返回可以获得的最大报酬。

注意，时间上出现重叠的 2 份工作不能同时进行。

如果你选择的工作在时间 `X` 结束，那么你可以立刻进行在时间 `X` 开始的下一份工作。



##### 排序+二分查找+动态规划

将startTime、endTime、profit作为一份工作的数据放入一个二维数组中，按照结束时间升序排序备用。

定义dp[i]表示有i份兼职工作时能获得的最大报酬，dp[0]=0表示没有工作时收入为0.

对于任意i份工作：
$$
dp[i]=max(dp[i-1],dp[k]+profit[i-1])
$$
其中k表示在第i份工作开始时间之前能完成的工作数量，因为我们已经按照结束时间升序排序了工作信息，故可以使用二分查找找到这个k，而c++的algorithm库的二分查找函数upper_bound(), lower_bound()分别是寻找>, >=的值，此时的解决方法是：将查找出的k-1作为我们需要的k，因为upper_bound()返回的是第一个大于目标值的数，则k-1必然是小于等于目标的



```c++
class Solution {
public:
    int jobScheduling(vector<int> &startTime, vector<int> &endTime, vector<int> &profit) {
        int n = startTime.size();
        vector<vector<int>> jobs(n);
        for (int i = 0; i < n; i++) {
            jobs[i] = {startTime[i], endTime[i], profit[i]};
        }
        sort(jobs.begin(), jobs.end(), [](const vector<int> &job1, const vector<int> &job2) -> bool {
            return job1[1] < job2[1];
        });
        vector<int> dp(n + 1);
        for (int i = 1; i <= n; i++) {
            int k = upper_bound(jobs.begin(), jobs.begin() + i - 1, jobs[i - 1][0], [&](int st, const vector<int> &job) -> bool {
                return st < job[1];
            }) - jobs.begin();
            dp[i] = max(dp[i - 1], dp[k] + jobs[i - 1][2]);
        }
        return dp[n];
    }
};
```

