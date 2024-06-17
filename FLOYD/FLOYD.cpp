// vo cuc thay bang 1000000001
// n la so dinh
// q la so truy van duong di
//input co dang:
// n q
//ma tran n*n
// q truy van
#include <bits/stdc++.h>
using namespace std;

int n, q;
int a[100][100],d[100][100],e[100][100];
int vs[100];
vector<pair<int,int>> v;
void input() {
	cout << "Nhap so dinh cua ma tran: ";
    cin >> n;
    cout << "Nhap ma tran: "<< endl;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j]; 
        }
    }
    cout << "Nhap so truy van: ";
    cin >> q;
    for(int i=1;i<=q;i++){
        int x,y; cin >> x >> y;
        v.push_back({x,y});
    }
}

void output() {
    for(pair<int,int> it:v){
        if(d[it.first][it.second]==1000000001){
            cout << "Khong co duong di tu " << it.first << " den " << it.second << "." << endl;
        }
        else{
            cout << "Duong di ngan nhat tu " << it.first << " den " << it.second << " la: d[" << it.first << "][" << it.second << "]=" <<d[it.first][it.second] << endl;
            int u=it.first,v=it.second;
            int t=v;
            cout << "Duong di: " << v;
            while(e[u][t]!=u){
                t=e[u][t];
                cout << " <- " << t;
            }
            cout << " <- " << u << endl;
        }  
    }
}

void floyd(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            d[i][j]=a[i][j];
            e[i][j]=i;
        }
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(d[i][j] > d[i][k]+d[k][j]){
                    d[i][j]=d[i][k]+d[k][j];
                    e[i][j]=k;
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(d[i][i] < 0){
            return;
        }
    }
}
void solve(){
    input();
    floyd();
    output(); 
}

int main() {
    solve();
    return 0;
}

