#include <bits/stdc++.h>
using namespace std;

const int maxLen = 100000;
int spf[maxLen + 1];

void sieve(){
    for(int i = 1; i <= maxLen; i++) spf[i] = i;
    for(int i = 2; i * i <= maxLen; i++){
        if(spf[i] == i){
            for(int j = i * i; j <= maxLen; j += i){
                if(spf[j] == j) spf[j] = i;
            }
        }
    }
}

vector<int> getPrimes(int x){
    vector<int> primes;
    while(x > 1){
        int p = spf[x];
        primes.push_back(p);
        while(x % p == 0) x /= p;
    }
    return primes;
}

int main(){
    sieve();
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int& x: arr) cin >> x;

    unordered_map<int, int> best;
    int ans = 1;

    for(int i = 0; i < n; i++){
        vector<int> primes = getPrimes(arr[i]);

        int bestVal = 0;
        for(int p: primes) bestVal = max(bestVal, best[p]);

        int curr = bestVal + 1;
        for(int p: primes){
            best[p] = max(best[p], curr);
        }

        ans = max(ans, curr);
    }
    cout << ans;
    return 0;
}