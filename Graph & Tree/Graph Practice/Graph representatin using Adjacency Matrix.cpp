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
#define ali()       	int main()

const int N = 1e3 + 10 ;
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


int graph1[N][N];

ali()
{
	Bismillah();

        test_case(){
            int n, m, k, q, val, sum = 0, ans = 0, cnt = 0;

            cin >> n >> m; // n = number of vertic and m = number of edges
            int v1, v2 ;
            vin g[n+1];
            for(int i=0; i<m; i++){
                cin >> v1 >> v2;
                graph1[v1][v2] = 1 ;
                graph1[v2][v1] = 1 ;
            } 

            for(int i=1; i<=n; i++){
                for(int j = 1 ; j<=n; j++){
                        cout << graph1[i][j] << ' ';
                }
                cout << endl;
            }

            


        }



	return 0 ;
}



/*

check negative value then mx = -1e9
check ll and int
indexing of string always start with i=0;

*/

