int n,a[100][100],vs[100],e[100];
void DFS(int u){
	vs[u]=1;
	for(int v=1;v<=n;v++){
		if(vs[v]==0 && a[u][v]==1){
			e[v]=u;
			DFS(v);
		}
	}
}
void Tree_DFS(int u){
	for(int v=1;v<=n;v++){
		vs[v]=0;
	}
	DFS(u);
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