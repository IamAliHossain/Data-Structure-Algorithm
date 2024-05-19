#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+10;

bool vis[N];
vector<int> g[N];
int level[N];

void bfs(int vertex){
    
    queue<int> q;
    q.push(vertex);
    vis[vertex] = true;

    while(q.size()){
        int cur_ver = q.front();
        q.pop();
        for(auto child : g[cur_ver]){
            if(!vis[child]){
                q.push(child);
                vis[child] = true;
                level[child] = level[cur_ver] + 1;
            }
        }
    }
    
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, ed; cin >> n >> ed;
    for(int i=0; i<ed; i++){
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
}