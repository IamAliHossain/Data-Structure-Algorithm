#include<bits/stdc++.h>
using namespace std;


const int N = 1e5+10;

bool vis[N];
vector<int> graph[N];

void dfs(int vertex){
    vis[vertex] = true;
    for(auto child : graph[vertex]){
        if(vis[child])continue;
        dfs(child);
    }
}


int main()
{
    int v, ed;
    cin >> v >> ed;
    int x, y;
    for(int i=1; i<=ed; i++){
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    int ct = 0 ;
    for(int i=1; i<=v; i++){
        if(vis[i])continue;
        dfs(i);
        ct++;
    }
    cout << ct << endl;
}