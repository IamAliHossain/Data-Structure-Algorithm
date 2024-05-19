
#include "bits/stdc++.h"
using namespace std;

/*LeetCode Problem(200) : Number of Islands */

void dfs(int i, int j, vector<vector<char>>& grid){
    int n = grid.size();
    int m = grid[0].size();
    if(i < 0 || j < 0) return ;
    if(i >= n || j >= m) return ;
    if(grid[i][j] == '0') return ;

    grid[i][j] = '0';
    dfs(i-1, j, grid);
    dfs(i+1, j, grid);
    dfs(i, j-1, grid);
    dfs(i, j+1, grid);
}

int numIslands(vector<vector<char>>& grid) {
    
    int n = grid.size();
    int m = grid[0].size();
    int cnt = 0 ;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(grid[i][j] == '1'){
                dfs(i, j, grid);
                cnt++;
            }
        }
    }
    cout << cnt << endl;;
}

