// vo cuc thay bang 1000000001
// n la so dinh
// q la so truy van duong di
//input co dang:
// n q
//ma tran n*n
// q truy van
//Su dung Sublime Text hoac VScode de chay file
#include <bits/stdc++.h>
using namespace std;

int n, q;
int a[100][100],d[100][100],e[100][100];
int vs[100];
vector<pair<int,int>> v;
void input() {
    ifstream inp("input.txt"); 
    inp >> n;
    inp >> q;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            inp >> a[i][j]; 
        }
    }
    for(int i=1;i<=q;i++){
        int x,y; inp >> x >> y;
        v.push_back({x,y});
    }
    inp.close(); 
}

void output() {
    ofstream out("output.txt"); 
    for(pair<int,int> it:v){
        if(d[it.first][it.second]==1000000001){
            out << "Khong co duong di tu " << it.first << " den " << it.second << "." << endl;
        }
        else{
            out << "Duong di ngan nhat tu " << it.first << " den " << it.second << " la: d[" << it.first << "][" << it.second << "]=" <<d[it.first][it.second] << endl;
            int u=it.first,v=it.second;
            int t=v;
            out << "Duong di: " << v;
            while(e[u][t]!=u){
                t=e[u][t];
                out << " <- " << t;
            }
            out << " <- " << u << endl;
        }  
    }
    out.close(); 
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