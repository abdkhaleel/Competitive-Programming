#include <bits/stdc++.h>
using namespace std;

int f(long long n){
    if(n % 2 == 0) return n / 2;
    for(long long i = 3; i * i <= n; i += 2){
        if(n % i == 0) return 1 + (n - i) / 2;
    }
    return 1;
}

int main(){
    long long n;
    cin >> n;
    int count = f(n);
    cout<<count;
    return 0;
}