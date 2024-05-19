#include "bits/stdc++.h"
using namespace std;


#define ll  			long long int
#define nl			    "\n"
#define yes 			cout << "YES\n"
#define no  			cout << "NO\n"
#define lower(s)        transform(s.begin(), s.end(), s.begin(), ::tolower);
#define upper(s)        transform(s.begin(), s.end(), s.begin(), ::toupper);
#define vin 			vector<int>
#define vln 			vector<ll>
#define pb  			push_back
#define all(x) 			(x).begin(), (x).end()
#define rall(x) 		(x).rbegin(), (x).rend()
#define FASTIO 		    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)


const int N = 1e6 + 10 ;
const ll MOD = 1e9 + 7 ;
/*  
    Problem :
    Given Q queries Q<= 10^5;
    In each query given V
    Print subtree_sum of V, Number of even numbers in subtree of V.
*/
vector<int> tree[N];
int subtree_sum[N];
int even_ct[N];

void dfs(int vertex, int parent){
    subtree_sum[vertex] += vertex ;
    if(vertex % 2 == 0){
        even_ct[vertex]++;
    }
    for(auto child : tree[vertex]){
        if(child == parent)continue;
        dfs(child, vertex);
        subtree_sum[vertex] += subtree_sum[child];
        even_ct[vertex] += even_ct[child];
    }
}


int main()
{
	
        FASTIO ;
        ll n;
        cin >> n ;
        for(int i=0;i<n-1; i++){
            int x, y;
            cin >> x >> y;
            tree[x].pb(y);
            tree[y].pb(x);
        }
        dfs(1,0);
        int q = 1 ;
        //cin >> q ;
        for(int i=1; i<=n; i++){
            cout << subtree_sum[i] <<" "<< even_ct[i] << nl;
        }

	return 0 ;
}



/*

check negative value then mx = -1e9
check ll and int
indexing of string always start with i=0;

*/

