#include<bits/stdc++.h>
using namespace std;

const int N = 1e6+10;
int parent[N];
vector<int> g[N];

void dfs(int vertex, int par = -1){
    parent[vertex] = par ;
    for(auto child : g[vertex]){
        if(child == par)continue;
        dfs(child, vertex);
    }
}
vector<int> path(int v){
    vector<int>ans;
    ans.push_back(v);
    while(parent[v] != -1){
        ans.push_back(parent[v]);
        v = parent[v];
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    int n; cin >> n;
    for(int i=1; i<n; i++){
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1);
    int a, b ; cin >> a >> b;
    vector<int> f, l;
    f = path(a);
    l = path(b);
    int lca = -1;
    int mn_len = min(f.size(), l.size());
    for(int i=0; i<mn_len; i++){
        if(f[i] == l[i]){
            lca = f[i];
        }
        else break;
    }
    cout << lca << endl;
    // for(auto u : f){
        
    //     cout << u << ' ';
    // }cout << endl;
    // for(int i=1; i<=n; i++){
    //     cout << i << " " << parent[i] <<endl;

    // }cout << endl;
}