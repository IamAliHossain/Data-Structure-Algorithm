#include<bits/stdc++.h>
using namespace std;

const int N = 1e6;

/* To know details read--> https://iishanto.com/sparse-table-bangla-tutorial/*/

int main(){

    int n = 8 ;
    
    int a[]={1,-2,4,3,-5,6,3,-82,-22};
    // int a[]={1,-2,4,3,-5,6,3,2};
    int l = 2, r = 7 ;
    
    int maxk = __lg(n);
    int sparse_table[maxk+1][n];

    for(int k = 0 ; k<maxk; k++){

        int subArraySize = (1<<k);
        for(int column = 0; column+subArraySize-1< n; column++){
            if(k == 0){
                sparse_table[k][column] = a[column] ;
            }
            else{
                int next = column + (1 << (k-1)) ;
                sparse_table[k][column] = min(sparse_table[k-1][column], sparse_table[k-1][next]);
            }
        }
    }
    int range = __lg(r - l + 1);
    int subArray_range = (1 << range);
    int ans = min(sparse_table[range][l], sparse_table[range][r - subArray_range + 1]);
    
    cout << ans << endl;
 

}