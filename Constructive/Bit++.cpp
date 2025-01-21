#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int x = 0;
    while(n){
        string ip;
        cin>>ip;
        x = ip[1] == '+'? x + 1: x - 1;
        n--;
    }
    cout<<x;
    return 0;
}