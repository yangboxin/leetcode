class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums,int k){
	int total=accumulate(nums.begin(), nums.end(),0);
	if(total%k!=0)
		return false;
	int target=total/k;
	int n=nums.size();
	vector<bool> available(1<<n,1);
	sort(nums.begin(), nums.end());
    if(nums.back()>target)
        return false;
	function<bool(int,int)> traceback=[&](int s,int p)->bool{
		if(s==0)
			return true;
		if(!available[s])
			return available[s];
		available[s]=0;
		for(int i=0;i<n;i++){
			if(nums[i]+p>target)
				break;
			if((s>>i)&1)
				if(traceback(s^(1<<i),(p+nums[i])%target))
					return true;
		}
        return false;
	};
	return traceback((1<<n)-1,0);
}
};
