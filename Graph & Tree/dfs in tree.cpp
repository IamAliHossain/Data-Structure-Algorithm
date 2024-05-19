#include "bits/stdc++.h"
using namespace std;


#define ll  			long long int
#define nl			    "\n"
#define yes 			cout << "YES\n"
#define no  			cout << "NO\n"
#define lower(s)            transform(s.begin(), s.end(), s.begin(), ::tolower);
#define upper(s)            transform(s.begin(), s.end(), s.begin(), ::toupper);
#define vin 			vector<int>
#define vln 			vector<ll>
#define pb  			push_back
#define all(x) 			(x).begin(), (x).end()
#define rall(x) 		(x).rbegin(), (x).rend()
#define FASTIO 		    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)


const int N = 1e6 + 10 ;
const ll MOD = 1e9 + 7 ;

vector<int> tree[N];
int depth[N];
int height[N];

void dfs(int vertex, int parent){
    
    for(int child : tree[vertex]){
        if(child == parent)continue;
        depth[child] = depth[vertex] + 1;
        dfs(child, vertex);
        height[vertex] = max(height[vertex], height[child] + 1);
    }
}

int main()
{
	
        FASTIO ;
        
        int t = 1 ;
        //cin >> t ;
        while(t--){

            ll n, m, k, q ;
           
            cin >> n ;
            for(int i=0; i<n; i++){
                int x, y;
                cin >> x >> y ;
                tree[x].pb(y);
                tree[y].pb(x);
            }
            
            dfs(1, 0);
            for(int i=1; i<=n; i++){
                cout << depth[i] << ' ' << height[i] << nl;
            }


            // for(auto [ x, y ] : pair){
            //     cout << x << ' ' << y << endl;
            // }


        }

	return 0 ;
}



/*

check negative value then mx = -1e9
check ll and int
indexing of string always start with i=0;

*/

