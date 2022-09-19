class Solution{
public:
	vector<int> dir={0,-1,0,1,0};
	bool valid(int x,int y,int n){
		if(x>=0&&x<n&&y>=0&&y<n)
			return true;
		return false;
	}
	int dfs(vector<vector<int>>& grid,int x,int y,vector<vector<int>>& tag,int t){
		int n=grid.size();
		int res=1;
		tag[x][y]=t;
		for(int i=0;i<4;i++){
			int x1=x+dir[i],y1=y+dir[i+1];
			if(valid(x1,y1,n)&&grid[x1][y1]==1&&tag[x1][y1]==0){
				res+=dfs(grid,x1,y1,tag,t);
			}
		}
		return res;
	}
	int largestIsland(vector<vector<int>>& grid){
		int n=grid.size(),res=0;
		vector<vector<int>> tag(n,vector<int>(n));
		unordered_map<int,int> area;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(grid[i][j]==1&&tag[i][j]==0){
					int t=i*n+j+1;
					area[t]=dfs(grid,i,j,tag,t);
				}
			}
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(grid[i][j]==0){
					int z=i;
					unordered_set<int> connected;
					for(int k=0;k<4;k++){
						int x=i+dir[k],y=j+dir[k+1];
						if(!valid(n,x,y)||tag[x][y]==0||connected.count(tag[x][y]))
							continue;
						z+=area[tag[x][y]];
						connected.insert(tag[x][y]);
					}
					res=max(res,z);
				}
			}
		}
		return res;
	}
};