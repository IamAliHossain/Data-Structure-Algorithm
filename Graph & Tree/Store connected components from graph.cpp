#include"bits/stdc++.h"
using namespace std;

const int N = 1e5+10;

bool vis[N];
vector<int>current_cc;
vector<vector<int>> cc;
vector<int> graph[N];

void dfs(int vertex){
    current_cc.push_back(vertex);
    vis[vertex] = true;
    for(auto child : graph[vertex]){
        if(vis[child])continue;
        dfs(child);
    }
}

int main()
{
    int n , ed;
    cin >> n >> ed;
    int x, y;
    for(int i=1; i<=ed; i++){
        cin >> x >> y ;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    for(int i=1; i<=n; i++){
        if(vis[i])continue;
        current_cc.clear();
        dfs(i);
        cc.push_back(current_cc);
    }
    cout << cc.size() << endl;
    for(int i=0; i<cc.size(); i++){
        for(auto u : cc[i]){
            cout << u << ' ';
        }cout << endl;
    }
       
}