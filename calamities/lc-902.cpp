class Solution{
public:
	int g[11];
	int atMostNGivenDigitSet(vector<string>& digits,int n){
		vector<int> d;
		for(auto& s:digits)
			d.push_back(s[0]-'0');
		string strn=to_string(n);
		int len=strn.size();
		int m=d.size();
		int res=0;
		g[0]=1;
		for(int i=1;i<=len;i++)
			g[i]=g[i-1]*m;
		for(int i=1;i<len;i++)
			res+=g[i];
		for(int i=0;i<len;i++){
			int k=lower_bound(d.begin(), d.end(),strn[i]-'0')-d.begin();
			res+=k*g[len-i-1];
			if(k!=m && d[k]==strn[i]-'0'){
				if(i==len-1)
					res++;
				continue;
			}
			else
				break;
		}
		return res;
	}
};
