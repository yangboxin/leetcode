考虑当前位置如果是一个负数的话，那么我们希望以它前一个位置结尾的某个段的积也是个负数，这样就可以负负得正，并且我们希望这个积尽可能「负得更多」，即尽可能小。如果当前位置是一个正数的话，我们更希望以它前一个位置结尾的某个段的积也是个正数，并且希望它尽可能地大。于是这里我们可以再维护一个 

fmin(i)它表示以第 ii 个元素结尾的乘积最小子数组的乘积，那么我们可以得到这样的动态规划转移方程：


$$
fmax(i)=max\sum_i^n{fmax(i-1)*a_i,fmin(i-1)*a_i,a_i}
fmax(i)=min\sum_i^n{fmax(i-1)*a_i,fmin(i-1)*a_i,a_i}
$$
它代表第 ii 个元素结尾的乘积最大子数组的乘积 fmax(i),可以考虑把 ai 加入第 i - 1 个元素结尾的乘积最大或最小的子数组的乘积中，二者加上 ai ，三者取大，就是第 ii 个元素结尾的乘积最大子数组的乘积。第 ii 个元素结尾的乘积最小子数组的乘积 fmin(i) 同理。

```c++
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxF = nums[0], minF = nums[0], ans = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            int mx = maxF, mn = minF;
            maxF = max(mx * nums[i], max(nums[i], mn * nums[i]));
            minF = min(mn * nums[i], min(nums[i], mx * nums[i]));
            ans = max(maxF, ans);
        }
        return ans;
    }
};

```

