#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
const int sz = 2e5+5;

/*

Problem Link : https://cses.fi/problemset/task/1646 
Author : Ali Hossain

*/

ll ar[sz];
ll st[sz*4];

void build_tree(int node, int b, int e){
    if(b == e){
        st[node] = ar[b];
        return;
    }
    int left = node << 1;
    int right = (node << 1) + 1;
    int mid = (b+e) >> 1;
    build_tree(left, b, mid);
    build_tree(right, mid+1, e);
    st[node] = st[left] + st[right];
}

ll query(int node, int b, int e, int l, int r){// range is [l, r]
    if(e < l || r < b){
        return 0;
    }
    if(b >= l && e <= r){
        return st[node];
    }
    int left = node << 1;
    int right = (node << 1) + 1;
    int mid = (b+e) >> 1;

    ll p1 = query(left, b, mid, l, r);
    ll p2 = query(right, mid+1, e, l, r);
    return (p1+p2);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, q; cin >> n >> q ;
    for(int i=1; i<=n; i++){
        cin >> ar[i];
    }
    build_tree(1,1, n);
    while(q--){
        int l, r; cin >> l >> r;
        ll ans = query(1, 1, n, l, r);
        cout << ans << endl;
    }
}