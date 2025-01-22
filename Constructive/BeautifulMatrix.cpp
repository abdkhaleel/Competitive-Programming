#include <bits/stdc++.h>
using namespace std;
int main(){
    int matrix[5][5];
    int ri, rj;
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            cin>>matrix[i][j];
            if(matrix[i][j] == 1){
                ri = i;
                rj = j; 
            }
        }
    }
    cout<<abs(2-ri) + abs(2-rj);
    return 0;
}