int n,a[100][100],e[100],vs[100];
int TPLT_DFS(int a[][]){
	int so_tplt=0;
	for(int i=1;i<=n;i++){
		if(vs[i]==0){
			so_tplt++;
			DFS(i);
		}
	}
	return so_tplt;	
}