//
//  main.cpp
//  test
//
//  Created by 杨博欣 on 2022/8/27.
//
#include<stack>
#include<iostream>
#include<string>
#include<unordered_map>
#include<vector>
using namespace std;
/*
Monotonic Stack
*/
class Solution {
public:
    long mod=1e9+7;
    int totalStrength(vector<int>& strength) {
        int n=strength.size();
        stack<int> ms;
        vector<int> nextsmaller(n,n);
        vector<int> prevsmaller(n,-1);
        vector<int> ss(n);
        int s=0;
        ss[0]=strength[0];
        s=strength[0];
        for(int i=0;i<n;i++){
            if(i){
                s=(s+strength[i])%mod;
                ss[i]=(1LL)*(s+ss[i-1])%mod;
            }          
            while(!ms.empty()&&strength[i]<strength[ms.top()]){
                nextsmaller[ms.top()]=i;
                ms.pop();
            }
            if(!ms.empty())
                prevsmaller[i]=ms.top();
            ms.push(i);
        }
        auto func=[&](int l,int r)->long{
            if(r<0)
                return 0;
            if(l<0)
                return ss[r];
            return (ss[r]-ss[l]+mod)%mod;
        };
        long res=0;
        for(int i=0;i<n;i++){
            int l=prevsmaller[i]+1,r=nextsmaller[i]-1;
            int equation_left=1LL*func(i-1,r)*(i-l+1)%mod;
            int equation_right=1LL*func(l-2,i-1)*(r-i+1)%mod;
            res+=1LL*strength[i]*((equation_left-equation_right+mod)%mod)%mod;
            res%=mod;
        }
        return res;
    }
};


int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> arr={1,3,1,2};
    Solution sol;
    sol.totalStrength(arr);
}
