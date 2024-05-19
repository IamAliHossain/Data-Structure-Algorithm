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


const int N = 1e5 + 10 ;
const ll MOD = 1e9 + 7 ;


ll power_of_2(ll a , ll b ){

    if( b == 0 )return 1;
    if( b % 2 == 0 ){
        ll val = power_of_2(a, b/2);
        return (( val % MOD )*(val % MOD )) % MOD ;
    }
    else{
        return ( a *(power_of_2(a, b-1) % MOD ))% MOD ;
    }

}


void Bismillah(){

	Do_Fast();

//	 #ifndef ONLINE_JUDGE
//	 freopen("input.txt", "r", stdin);
//	 freopen("output.txt", "w", stdout);
//	 #endif // ONLINE_JUDGE
}

vin graph[N];
bool vis[N];

void dfs(int vertex){
    /*Take action on vertex after entering the vertex*/
    //cout << vertex << " " << endl;
    vis[vertex] = true;
    for(int child : graph[vertex]){
       //cout << "Parent Node : " << vertex << " Child : " << child << endl;*/
        if(vis[child])continue;
        /*Take action on child before entering the child node*/
        dfs(child);
        /*Take action on child after exiting the child node*/
    }
    /*Take action on vertex before exiting the vertex*/
}



int main()
{
	Bismillah();

        test_case(){
        ll n, m, k, q ;

            cin >> n >> m;
            int x, y ;
            for(int i=1; i<=m; i++){
                cin >> x >> y ;
                graph[x].pb(y);
                graph[y].pb(x);
            }
            dfs(1);
        }
        
	return 0 ;
}



/*

check negative value then mx = -1e9
check ll and int
indexing of string always start with i=0;

*/

