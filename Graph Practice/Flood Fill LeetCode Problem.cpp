#include "bits/stdc++.h"
using namespace std;

/*LeetCode Problem : Flood Fill*/
void dfs(int i, int j, int initialColor, int newColor, vector<vector<int>>& image){
    int n = image.size();
    int m = image[0].size();
    if( i < 0 || j < 0) return;
    if(i >= n || j >= m) return;
    if(image[i][j] != initialColor) return;

    image[i][j] = newColor ;

    dfs(i-1, j, initialColor, newColor, image);
    dfs(i+1, j, initialColor, newColor, image);
    dfs(i, j-1, initialColor, newColor, image);
    dfs(i, j+1, initialColor, newColor, image);
}

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
    int initialColor = image[sr][sc];
    int newColor = color;
    if( initialColor != newColor)
        dfs(sr, sc, initialColor, newColor, image);
        return image;
}






/*

check negative value then mx = -1e9
check ll and int
indexing of string always start with i=0;

*/

