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
        cout << "Duong di ngan nhat tu dinh " << u << "den dinh " << v << "la: d[" << v << "] = " << d[v] << endl;
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
void Dijkstra(){
    for(int v=1;v<=n;v++){
        d[v]=a[u][v];
        e[v]=u;
        vs[v]=0;
    }
    d[u]=0;
    vs[u]=1;
    e[u]=0;
    while(true){
        int s=0,min=1e9;
        for(int v=1;v<=n;v++){
            if(vs[v]==0 && d[v] < min){
                min=d[v];
                s=v;
            }
        }
        if(s==0){
            return;
        }
        vs[s]=1;
        for(int v=1;v<=n;v++){
            if(vs[v]==0){
                if(d[v] > d[s] + a[s][v]){
                    d[v] = d[s] + a[s][v];
                    e[v]=s;
                }
            }
        }
    }
}
void solve(){
    input();
    Dijkstra();
    output(); 
}

int main() {
    solve();
    return 0;
}
