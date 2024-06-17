int n,a[100][100],vs[100],e[100];
queue<int> q;
void BFS(int u){
	q.push(u);
	vs[u]=1;
	while(!q.empty()){
		int x=q.front();
		q.pop();
		for(int v=1;v<=n;v++){
			if(vs[v]==0 && a[x][v]==1){
				q.push(v);
				vs[v]=1;
				e[v]=x;
			}
		}
	}
}