#include <bits/stdc++.h>
using namespace std;
int main(){
    string str;
    cin>>str;
    int n = str.size();

    for(int i = 0; i < n; i++){
        int digit = str[i] - '0';
        int inverted = 9 - digit;
        if(inverted < digit){
            if(i == 0 && inverted == 0){
                continue;
            }
            str[i] = inverted + '0';
        }
    }
    cout<<str;
    return 0;
}