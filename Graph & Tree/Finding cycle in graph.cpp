#include"bits/stdc++.h"
using namespace std;

const int N = 1e5+10;

bool vis[N];
vector<int> graph[N];

bool isCycleExist = false ;
bool dfs(int vertex, int parent){
    vis[vertex] = true;
    for(auto child : graph[vertex]){
        if(vis[child] && child == parent)continue;
        if(vis[child]) return true;
        isCycleExist |= dfs(child, vertex);
    }
    return isCycleExist ;
}

int main()
{
    int n, ed;
    cin >> n >> ed;
    for(int i=1;i<=ed; i++){
        int x,y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    bool ok = 0 ;
    for(int i=1; i<=n; i++){
        if(vis[i])continue;
        if(dfs(i,0)){
            ok = 1 ;
            break;
        }
    }
    if(ok)cout << ok << endl;
    else cout << 0 << endl;
}