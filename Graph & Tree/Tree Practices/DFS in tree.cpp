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
vin tree[N];
int depth[N], height[N];

void dfs(int vertex, int parent){
    
    for(auto child : tree[vertex]){
        if(child == parent )continue;
        depth[child] = depth[vertex] + 1 ;
        dfs(child, vertex);
        height[vertex] = max(height[vertex] ,height[child] + 1) ; 
    }
}



int main()
{
	Bismillah();

    int n , x, y;
    cin >> n ;
    for(int i=1; i<=n-1; i++){ // Tree te no.of edges = num of nodes - 1;
        cin >> x >> y;
        tree[x].pb(y);
        tree[y].pb(x);
    }
    dfs(1, 0);//default parent = 0 ;
  
    cout << "Depth of the trees are :";
    for(int i=1; i<=n; i++){
        cout << depth[i] << ' ';
    }cout << endl;
    cout << "Height of the trees are :";
    for(int i=1; i<=n; i++){
        cout << height[i] << ' ';
    }cout << endl;
	return 0 ;
}



/*

check negative value then mx = -1e9
check ll and int
indexing of string always start with i=0;

*/

