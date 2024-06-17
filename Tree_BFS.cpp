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
void Tree_DFS(int u){
	for(int v=1;v<=n;v++){
		vs[v]=0;
	}
	BFS(u);
	int dem=0;
	for(int v=1;v<=n;v++){
		if(vs[v]==1){
			dem++;
		}
	}
	if(dem == n){
		for(int v=1;v<=n;v++){
			if(e[v]!=0) cout << v << " " << e[v] << endl;
		}
	}
	else cout << "Khong co cay khung."; 
}