int n,a[100][100],vs[100],e[100];
void DFS(int u){
	cout << u << " ";
	vs[u]=1;
	for(int v=1;v<=n;v++){
		if(vs[v]==0 && a[u][v]==1){
			e[v]=u;
			DFS(v);
		}
	}
}