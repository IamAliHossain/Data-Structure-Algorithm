
/*HackerEarth Problem*/

#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+10;


vector<int> graph[N];
bool vis[N];

vector<vector<int> > cc;
vector<int>current_cc;

void dfs(int vertex){

    current_cc.push_back(vertex);
    vis[vertex] = true;
    for(auto child : graph[vertex]){
        if(vis[child])continue;
        dfs(child);
    }

}

int main(){
    int n , ed;
    cin >> n >> ed;
    for(int i=0; i<ed; i++){
        int x, y;
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
    for(auto current_cc : cc){
        for(auto vertex : current_cc){
            cout << vertex << ' ';
        }
        cout << endl;
    }
}
