### 最长重复子串



给定字符串 `S`，找出最长重复子串的长度。如果不存在重复子串就返回 `0`。



##### 二分查找+哈希表

用二分法枚举可能的重复子串的长度（0，n），在s中搜索是否有这样的重复子串出现



```c++
class Solution{
public:
	bool help(const string& s,int mid){
		unordered_set<string> uset;
		int n=s.size();
		for(int i=0;i<n;i++){
			string tmp=s.substr(i,mid);
			if(uset.count(tmp))
				return true;
			uset.insert(tmp);
		}
		return false;
	}
	int longestRepeatingSubstring(string s){
		int n=s.size();
		int l=0,h=n;
		while(l<h){
			int mid=(l+h+1)>>1;
			if(help(s,mid))
				l=mid;
			else
				h=mid-1;
		}
		return l;
	}
};
```

