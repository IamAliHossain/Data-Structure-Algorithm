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

void dfs(int i, int j, int initialColor, int newColor, vector<vector<int>>& image){
    int n = image.size();
    int m = image[0].size();
    if( i < 0 || j < 0) return;
    if(i >= n || j >= m) return;
    if(image[i][j] != initialColor) return;

    image[i][j] = newColor ;

    dfs(i-1, j, initialColor, newColor, image);
    dfs(i+1, j, initialColor, newColor, image);
    dfs(i, j-1, initialColor, newColor, image);
    dfs(i, j+1, initialColor, newColor, image);
}

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
    int initialColor = image[sr][sc];
    int newColor = color;
    if( initialColor != newColor)
        dfs(sr, sc, initialColor, newColor, image);
        return image;
}


int main()
{
	Bismillah();

        test_case(){
        ll n, m, k, q ;

            cin >> n >> m ;
            vin v(n);
            for(int i=0; i<n; i++){
                cin >> v[i];
            } 


        }

	return 0 ;
}



/*

check negative value then mx = -1e9
check ll and int
indexing of string always start with i=0;

*/

