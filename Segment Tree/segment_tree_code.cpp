#include<bits/stdc++.h>
using namespace std;
const int N=1e5+7;

int a[N];
int tree[N*3];

void init(int node, int b, int e){  /*node start from index 1, b-e means ei range e achi ekhon*/
    if(b == e){
        tree[node] = a[b] ;
        return ;
    }
    int left = node*2;
    int right = node*2 + 1 ;
    int mid = (b+e) / 2 ;
    init(left, b, mid);
    init(right, mid+1, e);
    tree[node] = tree[left] + tree[right] ;
}

/* if there is query for range sum then */

int query(int node, int b, int e, int i, int j){ /* i to j er sum korbe*/


    if(i > e || j < b){ /* range er baire chole geche */
        return 0 ;
    }

    if(b >= i and e <= j){ /* ermane relevant(valid) range */
        return tree[node];
    }
    int left = node * 2;
    int right = node * 2 + 1 ;
    int mid = (b+e)/ 2;

    int p1 = query(left, b, mid, i, j);
    int p2 = query(right, mid+1, e, i, j);
    return p1+p2;
}

int main(){
    int t ;
    cin >> t ;
    while(t--){

        int n , q; cin >> n >> q;
        for(int i=1; i<=n; i++){
            cin >> a[i];
        }
        init(1, 1 , n);
        while(q--){
            int l, r; cin >> l >> r;
            cout << query(1, 1, n, l, r) << endl;
        }
    }
    

}