#include"bits/stdc++.h"
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

#define Do_Fast		ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define test_case() 	int t; cin >> t; while(t--)


const int N = 1e5+10 ;

vector<int> graph[N];
bool vis[N];


void dfs(int vertex){

    vis[vertex] = true;

    for(auto child : graph[vertex]){
        if(vis[child])continue;
        dfs(child);
    }
}

int main(){

    Do_Fast ;
    int n, edg; 
    cin >> n >> edg;
    for(int i=0; i<edg; i++){
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    int cnt = 0 ;
    for(int i=1; i<=n; i++){
        if(vis[i])continue;
        dfs(i);
        cnt++;
    }
    cout << cnt << endl;
}