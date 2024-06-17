#include <bits/stdc++.h>
using namespace std;

int n, u;
int a[100][100],d[100],e[100];
int vs[100];
void input(){
	cout << "Nhap so dinh cua ma tran: ";
	cin >> n;
	cout << "Nhap dinh bat dau: ";
	cin >> u;
	cout << "Nhap ma tran: " << endl;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin >> a[i][j];
		}
	}
}
void output(){
	for(int v=1;v<=n;v++){
		cout << "Duong di ngan nhat tu dinh " << u << " den " << v << "la: d[" << v << "] = " << d[v] << endl;
		cout << "Duong di: ";
        int t=v;
        cout << v;
        while(t!=u){
            t=e[t];
            if(t!=u){
                cout << "<-" << t;

            }
        } 
        cout << "<-" << u << endl;
	}
}
void Bellman_Ford(){
	for(int v=1;v<=n;v++){
		d[v]=a[u][v];
		e[v]=u;
	}
	d[u]=0;
	e[u]=0;
	int ok=0;
	for(int dem=1;dem <= n-1;dem++){
		ok=1;
		for(int v=1;v<=n;v++){
			for(int k=1;k<=n;k++){
				if(d[v] > d[k]+a[k][v]){
					d[v]=d[k]+a[k][v];
					e[v]=k;
					ok=0;
				}
			}
		}
	}
}
void solve(){
    input();
    Bellman_Ford();
    output(); 
}

int main() {
    solve();
    return 0;
}