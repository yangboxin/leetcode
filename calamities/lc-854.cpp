class Solution {
public:
    int res=INT_MAX;
    void dfs(string& s1,string& s2,const int n,int cur,int ans){
        if(cur==n){
            res=min(ans,res);
            return;
        }
        if(ans>=res)
            return;
        if(s1[cur]!=s2[cur]){
            for(int i=cur+1;i<n;i++){
                if(s2[i]!=s1[i]&&s2[i]==s1[cur]){
                    swap(s2[i],s2[cur]);
                    dfs(s1,s2,n,cur+1,ans+1);
                    swap(s2[cur],s2[i]);
                }
            }
        }
        else{
            dfs(s1,s2,n,cur+1,ans);
        }
    }
    int kSimilarity(string s1, string s2) {
        dfs(s1,s2,s1.size(),0,0);
        return res;
    }
};