### 最大BST子树

给定一个二叉树，找到其中最大的二叉搜索树（BST）子树，并返回该子树的大小。其中，最大指的是子树节点数最多的。

**二叉搜索树（BST）**中的所有节点都具备以下属性：

- 左子树的值小于其父（根）节点的值。
- 右子树的值大于其父（根）节点的值。

**注意：**子树必须包含其所有后代。



##### 记忆化dfs

复用子树的信息，加快枚举判断的速度

```c++
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//Node:l,r表示当前节点为根的二叉搜索树里的值的范围[l,r]，sz为这棵树的节点数，如果不是BST,则sz=-1
struct Node{
    int l,r,sz;
};
class Solution {
    int ans=0;
public:
    Node dfs(TreeNode* root){
        if (root->left==NULL && root->right==NULL){
            ans=max(ans,1);
            return (Node){root->val,root->val,1};
        }
        int sz=1;
        bool valid=1;
        int l=root->val,r=root->val;// 起初的范围是[root->val,root->val]，再根据左右子树更新范围
        if (root->left!=NULL){
            Node L=dfs(root->left);
            if (L.sz!=-1 && root->val>L.r){
                sz+=L.sz;
                l=L.l;
            }
            else valid=0;
        }
        if (root->right!=NULL){
            Node R=dfs(root->right);
            if (R.sz!=-1 && root->val<R.l){
                sz+=R.sz;
                r=R.r;
            }
            else valid=0;
        }
        if (valid){
            ans=max(ans,sz);
            return (Node){l,r,sz};
        }
        // 不是BST，sz设为-1标记不是BST，l,r多少都可以
        return (Node){-1,-1,-1};
    }
    int largestBSTSubtree(TreeNode* root) {
        if (root==NULL) return 0;
        dfs(root);
        return ans;
    }
};

```

