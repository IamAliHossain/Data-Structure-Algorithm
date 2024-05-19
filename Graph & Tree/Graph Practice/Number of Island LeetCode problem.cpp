
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

void dfs(int i, int j, vector<vector<char>>& grid){
    int n = grid.size();
    int m = grid[0].size();
    
    if(i < 0 || j < 0) return ;
    if(i >= n || j >= m) return ;
    if(grid[i][j] == '0') return ;

    grid[i][j] = '0';

    dfs(i-1, j, grid);
    dfs(i+1, j, grid);
    dfs(i, j-1, grid);
    dfs(i, j+1, grid);
}


int main(){
    int n, m ;
    cin >> n >> m ;
    vector<vector<char>>grid;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            char ch; cin >> ch;
            grid[i].push_back(ch);
        }
    }

    int cnt = 0 ;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(grid[i][j] == '1'){
                dfs(i, j, grid);
                cnt++; 
            }
        }
    }
    show1(cnt);
    // cout << grid.size() << endl;
    // for(int i=0; i<n; i++){
    //     for(auto u : grid[i]){
    //         cout << u << ' ';
    //     }cout <<endl;
    // }

}















// int numIslands(vector<vector<char>>& grid) {
    
//     int n = grid.size();
//     int m = grid[0].size();
//     int cnt = 0 ;
//     for(int i=0; i<n; i++){
//         for(int j=0; j<m; j++){
//             if(grid[i][j] == '1'){
//                 dfs(i, j, grid);
//                 cnt++; 
//             }
//         }
//     }
//     return cnt ;
// }