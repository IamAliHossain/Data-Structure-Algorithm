#include<bits/stdc++.h>
using namespace std;

/* Problem Link : https://lightoj.com/problem/guilty-prince */


using ll = long long int ;

const int N = 21, M = 21;
char s[N][M];
int col, row ; 
bool vis[N][M];

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

ll cnt;
bool isValid(int i, int j){
    if((i >= 0 and i < row) and (j >=0 and j < col) and !vis[i][j] and s[i][j] == '.')  return true;
    return false;
}

void dfs(int i, int j){
    
    vis[i][j] = true;
    cnt++;
    for(int k = 0; k<4; k++){
        int newX = i + dx[k];
        int newY = j + dy[k];
        if(isValid(newX, newY)){
            dfs(newX, newY);
        }
    }
    
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin>> t;
    for(int tc =1; tc <=t; tc++){
        
        for(int i=0; i<=21; i++){
            for(int j=0; j<=21; j++){
                vis[i][j] = 0;
            }
        }
        cin >> col >> row;
        
        int x = 0, y = 0;
        cnt = 0;
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                cin >> s[i][j];
                if(s[i][j] == '@'){
                    x = i;
                    y = j;
                }
            }
        }
        
        dfs(x, y);
        cout << "Case " << tc << ": " << cnt << endl;

    }
}

/*
    // if(isValid(i+1, j)) dfs(i+1, j);
    // if(isValid(i-1, j)) dfs(i-1, j);
    // if(isValid(i, j+1)) dfs(i, j+1);
    // if(isValid(i, j-1)) dfs(i, j-1);
*/