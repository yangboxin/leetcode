class Solution{
public:
	int getID(int x,long w){
		return x<0?(x+1ll)/(w-1):x/w;
	}
	bool containNearbyAlmostDuplicate(vector<int>& nums,int k,int t){
		unordered_map<int,int> umap;
		int n=nums.size();
		for(int i=0;i<n;i++){
			long x=nums[i];
			int id=getID(x,t+1ll);
			if(umap.count(id))
				return true;
			if(umap.count(id+1) && abs(nums[i]+umap[id+1])<=t)
				return true;
			if(umap.count(id-1) && abs(nums[i]-umap[id-1])<=t)
				return true;
			umap[id]=x;
			if(i>=k)
				umap.erase(getID(nums[i-k],t+1ll));
		}
		return false;
	}	
};

