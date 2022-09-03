//
//  main.cpp
//  test
//
//  Created by 杨博欣 on 2022/8/27.
//
#include<stack>
#include<iostream>
#include<string>
#include<unordered_set>
#include<vector>
using namespace std;
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n=wordDict.size();
        unordered_set<int> uset;
        auto dfs=[&](auto&& me,string&& s1)->bool{
            if(s1.size()<s.size()){
                bool res=0;
                for(int i=0;i<n;i++){
                    if(uset.count(s1.size()+wordDict[i].size())||
                    wordDict[i]!=s.substr(s1.size(),wordDict[i].size()))
                    continue;
                    uset.insert(s1.size()+wordDict[i].size());
                    res=me(me,s1+wordDict[i]);
                    if(res)
                        return 1;
                }
                return res;
            }
            else
                return 1;
        };
        return dfs(dfs,"");
    }
};



int main(int argc, const char * argv[]) {
    // insert code here...
    string s="catsandog";
    vector<string> worddict;
    worddict.push_back("cats");
    worddict.push_back("dog");
    worddict.push_back("sand");
    worddict.push_back("and");
    worddict.push_back("cat");
    Solution sol;
    sol.wordBreak(s, worddict);
}
