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

int subtree_sum[N];
int value[N];
vector<int> tree[N];
/*incmplete thaklo*/
void dfs(int vertex, int parent = 0){
    for(auto child : tree[vertex]){
        if(child == parent)continue;
        dfs(child, vertex);
    }
}

int main()
{
	
        FASTIO ;
        
        int n; cin >> n ;
        for(int i=1; i<n; i++){
            int x , y;
            cin >> x >> y ;
            tree[x].pb(y);
            tree[y].pb(x);
        }

	return 0 ;
}



/*

check negative value then mx = -1e9
check ll and int
indexing of string always start with i=0;

*/

