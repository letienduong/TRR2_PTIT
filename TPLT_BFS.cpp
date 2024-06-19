int n,a[100][100],vs[100],e[100];
queue<int> q;
int TPLT_BFS(int a[][]){
	int so_tplt=0;
	for(int i=1;i<=n;i++){
		if(vs[i]==0){
			so_tplt++;
			BFS(i);
		}
	}
	return so_tplt;
}