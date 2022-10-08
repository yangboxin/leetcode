### 叶值的最小代价生成树

给你一个正整数数组 arr，考虑所有满足以下条件的二叉树：

每个节点都有 0 个或是 2 个子节点。
数组 arr 中的值与树的中序遍历中每个叶节点的值一一对应。（知识回顾：如果一个节点有 0 个子节点，那么该节点为叶节点。）
每个非叶节点的值等于其左子树和右子树中叶节点的最大值的乘积。
在所有这样的二叉树中，返回每个非叶节点的值的最小可能总和。这个和的值是一个 32 位整数。



##### 动态规划

```c++
class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
       int res=0,idx=0;
       while(arr.size()>1){
           int minleaf=INT_MAX;
           for(int i=0;i<arr.size()-1;i++){
               if(arr[i]*arr[i+1] < minleaf){
                   minleaf=arr[i]*arr[i+1];
                   idx=arr[i]<arr[i+1]?i:i+1;
               }
           }
           res+=minleaf;
           arr.erase(arr.begin()+idx);
       } 
       return res;
    }
};
```