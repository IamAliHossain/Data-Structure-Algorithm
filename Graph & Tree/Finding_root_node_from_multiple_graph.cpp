
#include<bits/stdc++.h>
using namespace std;

/*Problem Link : https://lightoj.com/problem/back-to-underworld */

using ll = long long int;

const int N= 2e5+10;
vector<int> g[N];
bool vis[N];
ll ans, cnt = 0;
vector<bool> root(N, 0);
vector<int> subtre(N, 1);

void dfs(int vertex, int par = -1){
    vis[vertex] = true;
    // subtre[vertex] = 1;
    if(par == -1)root[vertex] = 1;
    // subtre[vertex] = 1;
    for(auto child : g[vertex]){
        if(vis[child])continue;
        dfs(child, vertex);
        subtre[vertex] += subtre[child] ;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    for(int tc = 1; tc<=t; tc++){
        int n; cin >> n;
        
        for(int i=1; i<=N; i++){
            g[i].clear();
            vis[i] = 0 ;
            root[i] = 0;
            subtre[i] = 1;
        }
        set<int>se;
        for(int i=0; i<n; i++){
            int u , v; cin >> u >> v;
            g[v].push_back(u);
            g[u].push_back(v);
            se.insert(u);
            se.insert(v);

        }
        for(int i=1; i<=N; i++){
            if(vis[i] or se.find(i) == se.end())continue;
            dfs(i);
        }
        ans = 0;
        for(int i=1; i<=10; i++){
            if(root[i])cout << "Root " << i << ' ' << subtre[i] << endl;
            // else cout << 0 << ' '<< subtre[i] << endl;
            // cout << subtre[i] << ' ';
            if(root[i]){
                ans += (subtre[i]+1)/2;
            }
        }
        cout << endl;
        cout << "Case "<< tc << ": " << ans << endl;
    }
    
}
