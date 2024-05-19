#include "bits/stdc++.h"
using namespace std;


#define ll  			long long int
#define endl			"\n"
#define yes 			cout << "YES\n"
#define no  			cout << "NO\n"

#define dec             greater<int>()
#define lower(s)        transform(s.begin(), s.end(), s.begin(), ::tolower);
#define upper(s)        transform(s.begin(), s.end(), s.begin(), ::toupper);

#define vin 			vector<int>
#define vln 			vector<ll>
#define pb  			push_back
#define all(x) 			(x).begin(), (x).end()
#define rall(x) 		(x).rbegin(), (x).rend()
#define show1(x)		cout << x << endl;
#define show2(x, y)		cout << x << " " << y << endl;
#define delete			v.erase(remove(v.begin(), v.end(),k), v.end())

#define Do_Fast() 		ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define test_case() 	int t; cin >> t; while(t--)


const int N = 1e6 + 10 ;
const ll MOD = 1e9 + 7 ;

/*Big MOD or Binary Exponension*/
ll power(ll a , ll b ){

    if( b == 0 )return 1;

    ll val = power(a, b/2);
    if( b % 2 == 0 ){
        return (( val % MOD ) * (val % MOD )) % MOD ;
    }
    else{
        return ((val % MOD) * (val % MOD)) * a % MOD;
    }

}


void Bismillah(){

	Do_Fast();

//	 #ifndef ONLINE_JUDGE
//	 freopen("input.txt", "r", stdin);
//	 freopen("output.txt", "w", stdout);
//	 #endif // ONLINE_JUDGE
}

vin g[N];
bool vis[N];

bool isCycleExist = false ;
bool dfs(int vertex, int parent){
    vis[vertex] = true;
    for(auto child : g[vertex]){
        if(vis[child] && child == parent)continue;
        if(vis[child]) return true;

        isCycleExist |= dfs(child, vertex);

    }
    return isCycleExist ;
}


int main()
{
	Bismillah();

        //test_case(){
        ll n, m, k, q ;

            cin >> n >> m ;
            for(int i=0; i<m; i++){
                int x , y ;
                cin >> x >> y ;
                g[x].pb(y);
                g[y].pb(x);
            }

            bool ok = false ;
            for(int i=1; i<=n; i++){
                if(vis[i])continue;
                if( dfs(i, 0)){
                    ok = true;
                    break;
                }
            }
            cout << ok << endl;

        //}

	return 0 ;
}



/*

check negative value then mx = -1e9
check ll and int
indexing of string always start with i=0;

*/

