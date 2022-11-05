class Solution{
private:
	int cnt=0;
	int mi,ma;
	const int dirx1[16]={0,0,1,1,1,-1,-1,-1,1,2,-1,-2,1,2,-1,-2};
	const int diry1[16]={1,-1,1,0,-1,1,0,-1,2,1,2,1,-2,-1,-2,-1};
	const int dirx2[8]={0,0,2,2,2,-2,-2,-2};
	const int diry2[8]={2,-2,2,0,-2,2,0,-2};
public:
	int numberOfPatterns(int m,int n){
		vector<vector<bool>> visited(3,vector<bool>(3));
		mi=m;
		ma=n;
		visited[0][0]=true;
		dfs(0,0,1,visited);
		visited[0][0]=false;
		visited[0][1]=true;
		dfs(0,1,1,visited);
		visited[0][1]=false;
		int cnt2=cnt;
		visited[1][1]=true;
		dfs(1,1,1,visited);
		return cnt+cnt2*3;
	}
	void dfs(int x,int y,int depth,vector<vector<bool>>& visited){
		if(depth>=mi)
			cnt++;
		for(int i=0;i<16;i++){
			int newx=x+dirx1[i],newy=y+diry1[i];
			if(depth<ma&&newx>=0&&newx<3&&newy>=0&&newy<3&&!visited[newx][newy]){
				visited[newx][newy]=true;
				dfs(newx,newy,depth+1,visited);
				visited[newx][newy]=false;
			}
		}
		for(int i=0;i<8;i++){
			int newx=x+dirx2[i],newy=y+diry2[i];
			if(depth<ma&&newx>=0&&newx<3&&newy>=0&&newy<3&&!visited[newx][newy]&&visited[x+dirx1[i]][y+diry1[i]]){
				visited[newx][newy]=true;
				dfs(newx,newy,depth+1,visited);
				visited[newx][newy]=false;
			}
		}
	}
};