#include<bits/stdc++.h>
using namespace std;
const int N=3e5+7;

typedef long long ll;
ll a[N];
ll st[N*4];

void build_tree(int node, int b, int e){  /*node start from index 1, b-e means ei range e achi ekhon*/
    if(b == e){
        st[node] = a[b] ;
        return ;
    }
    int left = node*2;
    int right = node*2 + 1 ;
    int mid = (b+e) / 2 ;
    build_tree(left, b, mid);
    build_tree(right, mid+1, e);

    st[node] = st[left] + st[right] ;
}

/* if there is query for range sum then */

ll query(int node, int b, int e, int l, int r){ /* l to j er sum korbe*/
    
    if(e < l || b > r ){ /* range er baire chole geche */
        return 0 ;
    }

    if(b >= l and e <= r){ /* b-e [l, r] er vitore thakle valid range */
        return st[node];
    }
    int left = node * 2;
    int right = node * 2 + 1 ;
    int mid = (b+e)/ 2;

    int p1 = query(left, b, mid, l, r);
    int p2 = query(right, mid+1, e, l, r);
    return p1+p2;
}

/* When we need to update the value of an index */

void point_update(int node, int b, int e, int pos, int val){
    
    if(pos < b || pos > e){
        return;
    }
    if(b == e){
        st[node] = val; // updating value at given pos
        return;
    }
    int left = (node << 1);
    int right = (node << 1)+1;
    int mid = (b+e) >> 1;
    point_update(left, b, mid, pos, val);
    point_update(right, mid+1, e, pos, val);

    st[node] = (st[left] + st[right]);
}

int main(){
    int t ;
    cin >> t ;
    while(t--){

        int n , q; cin >> n >> q;
        for(int i=1; i<=n; i++){
            cin >> a[i];
        }
        build_tree(1, 1 , n);

        while(q--){
            int l, r; cin >> l >> r;
            cout << query(1, 1, n, l, r) << endl;
        }
    }
    

}