### 二叉树中最长的连续序列

给定二叉树的根 `root` ，返回树中**最长连续路径**的长度。
**连续路径**是路径中相邻节点的值相差 `1` 的路径。此路径可以是增加或减少。

- 例如， `[1,2,3,4]` 和 `[4,3,2,1]` 都被认为有效，但路径 `[1,2,4,3]` 无效。

另一方面，路径可以是子-父-子顺序，不一定是父子顺序。



##### dfs

记录父节点的值与当前节点的值比较即可。

```c++
class Solution {
public:
    int maxLen;

//  vector<int> pre;
//  vector<int> mid;
//  vector<int> post;

    int longestConsecutive(TreeNode* root) {
        //tuple的内容分别是节点,当前出栈的次数, increment数和decrement数
        stack<tuple<TreeNode*, int, int, int>> stk;
        //栈非空,或者root部位nullptr,继续循环
        while(!stk.empty() || root != nullptr){
            //当前节点不为空,压入当前节点,并且下个节点为其左节点
            if(root != nullptr){
                stk.push({root, 1, 1, 1});
                //前序遍历
                //pre.push_back(root->val);
                root = root->left;
            }
            //取出栈中最顶端的节点,看看是第一次访问还是第二次访问,如果是第一次访问,访问次数+1,继续访问右节点
            else{
                auto& [CurNode, Curcnt, Curinc, Curdec] = stk.top();
                //当前是第一次出栈
                if(Curcnt == 1){
                    Curcnt = 2;
                    //中序遍历
                    //mid.push_back(CurNode->val);
                    root = CurNode->right;
                }
                else{
                    //已经是右节点返回的节点了,在该节点pop前统计该节点的最大次数
                    maxLen = max(maxLen, (Curinc + Curdec - 1));
                    stk.pop();
                    //后续遍历
                    //post.push_back(CurNode->val);
                    //如果栈不为空,则将当前节点对其父节点的inc和dec影响数加到父节点上
                    if(!stk.empty()){
                        auto& [pointer, cnts, inc, dec] = stk.top();
                        if(pointer->val == CurNode->val - 1)
                            inc = max(Curinc + 1, inc);
                        if(pointer->val == CurNode->val + 1)
                            dec = max(Curdec + 1, dec);                        
                    }                    
                    root = nullptr;
                }
            }
        } 
        return maxLen;
    }
};
```

