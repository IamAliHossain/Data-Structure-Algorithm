
#include<bits/stdc++.h>
using namespace std;

/*Problem Link : https://lightoj.com/problem/back-to-underworld */

using ll = long long int;

const int N= 2e5+10;
vector<int> g[N];
bool vis[N];
int level[N];
ll ans, cnt = 0;
ll l, v ;

void bfs(int vertex){
    queue<int> q;
    q.push(vertex);
    vis[vertex] = true;

    while(!q.empty()){
        int cur_ver = q.front();
        q.pop();
        for(auto child : g[cur_ver]){
            if(!vis[child]){
                q.push(child);
                vis[child] = true;
                level[child] = level[cur_ver] + 1;
                if(level[child] & 1){
                    l++;
                }
                else{
                    v++;
                }
            }
        }
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
            level[i] = 0;
        }
        set<int>se;
        for(int i=0; i<n; i++){
            int u , v; cin >> u >> v;
            g[v].push_back(u);
            g[u].push_back(v);
            se.insert(u);
            se.insert(v);

        }

        ll ans = 0;
        for(auto u : se){
            if(!vis[u]){
                l =0, v = 0;
                bfs(u);
                if(level[u] & 1){
                    l++;
                }
                else{
                    v++;
                }
                ans += max(l, v);
            }
            // cout << u << ' ' << level[u] << endl;
        }
        cout << "Case "<< tc << ": " << ans << endl;
    }
    
}
