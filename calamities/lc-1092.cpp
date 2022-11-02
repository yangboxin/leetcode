class Solution {
    //首先求出LCS双方对应的最短串，然后往中间填充
    int f[1010][1010];
    string LCS;
public:
    string shortestCommonSupersequence(string & a, string & b) {
        int n = a.size(), m = b.size();
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= m; j++){
                if(a[i - 1] == b[j - 1]) {
                    f[i][j] = f[i - 1][j - 1] + 1;
                }
                else {
                    f[i][j] = max(f[i][j - 1], f[i - 1][j]);
                }
            }
        }
        //通过DP的信息倒推得到这个序列
        int i = n - 1,j =  m - 1;
        while(i >= 0 && j >= 0){
            if(a[i] == b[j]) LCS += a[i], i--, j--;
            else {
                if(f[i][j + 1] > f[i + 1][j]) i--;
                else j--;
            }
        }
        string ans;
        i = 0, j = 0;
        while(LCS.size()){
            while(i < n && a[i] != LCS.back()) ans += a[i++];
            while(j < m && b[j] != LCS.back()) ans += b[j++];
            ans += LCS.back();
            LCS.pop_back();
            i++, j++;
        }
        while(i < n) ans += a[i++];
        while(j < m) ans += b[j++];
        return ans;
    }
};
