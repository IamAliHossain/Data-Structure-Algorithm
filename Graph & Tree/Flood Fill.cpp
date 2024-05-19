#include<bits/stdc++.h>
using namespace std;

const int N = 1e6+10;
bool vis[N];

void dfs(int i, int j, int initialColor, int newColor, vector<vector<int>>& image){
    int n = image.size(), m = image[0].size();

    if(i < 0 and j < 0) return;
    if(i >=n and j >= m) return;
    if(image[i][j] != initialColor); return;
    image[i][j] = newColor;

    dfs(i-1, j,initialColor, newColor, image);
    dfs(i+1, j,initialColor, newColor, image);
    dfs(i, j-1,initialColor, newColor, image);
    dfs(i, j+1,initialColor, newColor, image);

}

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
    int initialColor = image[sr][sc];
    int newColor = color ;
    if(initialColor != newColor){
        dfs(sr, sc, initialColor, newColor, image);
        return image;
    }
}

int main(){
    int n ;
    return 0;
}