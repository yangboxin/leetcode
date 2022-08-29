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
class Solution {
public:
    vector<vector<int>> res;
    vector<int> tmp;
    vector<int> nums;
    void traceback(int x){
        if(x==nums.size()){
            if(tmp.size()>1)
                res.push_back(tmp);
            return;
        }
        if(tmp.empty() || nums[x]>=tmp.back()){
            tmp.push_back(nums[x]);
            traceback(x+1);
            tmp.pop_back();
        }
        if(!tmp.empty()&&nums[x]!=tmp.back())
            traceback(x+1);
        if(tmp.empty())
            traceback(x+1);
    }
    vector<vector<int>> findSubsequences(vector<int>& _nums) {
        int n=_nums.size();
        this->nums=_nums;
        traceback(0);
        return res;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> arr={4,6,7,7};
    Solution sol;
    sol.findSubsequences(arr);
}
