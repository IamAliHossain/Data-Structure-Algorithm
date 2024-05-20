#include<bits/stdc++.h>
using namespace std;
/*
 
    Problem Link : https://cses.fi/problemset/task/1651
    Author : Ali Hossain
 
*/
using ll = long long int;
const int N = 2e5+5;
 
ll ar[N];
ll st[N*4];
ll lazy[N*4];
 
void build_st(int node, int b, int e){
    if(b == e){
        st[node] = ar[b];
        return;
    }
    int left = (node << 1);
    int right = (node << 1) + 1;
    int mid = (b+e) >> 1;
    build_st(left, b, mid);
    build_st(right, mid+1, e);
 
    st[node] = st[left] + st[right];
}
 
// ll query(int node, int b, int e, int l, int r){
//     if(e < l || r < b){
//         return 0;
//     }
//     if(b >= l and e <= r){
//         return st[node];
//     }
//     int left= (node << 1);
//     int right = (node << 1) + 1;
//     int mid = (b+e) >> 1;
//     ll p1 = query(left, b, mid, l, r);
//     ll p2 = query(right, mid+1, e, l, r);
 
//     return (p1 + p2);
// }
 
void range_update(int node, int b, int e, int l, int r, int val){
    if(lazy[node] != 0){
        st[node] += (b - e +1) * val;
 
        if(b != e){
            int left = (node << 1);
            int right = (node << 1) + 1;
            lazy[left] += lazy[node];
            lazy[right] += lazy[node];
        }
        lazy[node] = 0;
    }
 
    if(e < l || r < b){
        return;
    }
    if(b >= l and e <= r){
        st[node] += (b - e + 1) * val;
        if(b != e){
            int left = (node << 1);
            int right = (node << 1) + 1;
            lazy[left] += val;
            lazy[right] += val;
        }
        return;
    }
    int left = (node << 1);
    int right = (node << 1) + 1;
    int mid = (b+e) >> 1;
 
    range_update(left, b, mid, l, r, val);
    range_update(right, mid+1, e, l, r, val);
 
    st[node] = st[left] + st[right];
}
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    int n, q; cin >> n >> q;
    for(int i=1; i<=n; i++){
        cin >> ar[i];
    }
    build_st(1, 1, n);
    while(q--){
        int type ; cin >> type;
        if(type == 1){
            int L, R, val; cin >> L >> R >> val;
            range_update(1, 1, n, L, R, val);
        }
        else{
            int pos; cin >> pos;
            cout << st[pos] << endl;
        }
    }
    return 0;
}