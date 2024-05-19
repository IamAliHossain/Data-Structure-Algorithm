#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10 ;

bool vis[N];

vector<int> graph[N];

bool dfs(int i, int j, vector<vector<char>> &grid){
    int n = grid.size();
    int m = grid[0].size();

    if(i < 0 || j < 0)return;
    if(i >= n || j >= m)return;
    if(grid[i][j] == '0')return;

    dfs(i-1, j, grid);
    dfs(i+1, j, grid);
    dfs(i, j-1, grid);
    dfs(i, j+1, grid);

}

int numIslands(vector<vector<char>> &grid){
    int n = grid.size();
    int m = grid[0].size();
    int ct = 0 ;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(grid[i][j] == '1')
            {   
                dfs(i, j, grid);
                ct++;
            }
        }
    }
    return ct;
}

int main()
{
    int n ;

    return 0;
}