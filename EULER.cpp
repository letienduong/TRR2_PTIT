int u;
stack<int> st,ce;

void EULER(int a[][]){
    st.push(u);
    while(!st.empty()){
        int ok = 0;
        int v = st.top();
        for(int i=1; i<=n; i++){
            if(a[v][i]==1){
                st.push(i);
                ok = 1;
                a[v][i] = 0;
                a[i][v] = 0; // Bo dong nay neu la do thi co huong
                break;
            }
        }
        if(ok==0){
            ce.push(v);
            st.pop();
        }
    }
    while(!ce.empty(){
    	cout << ce.top() << "-";
    	ce.pop();
    }
}