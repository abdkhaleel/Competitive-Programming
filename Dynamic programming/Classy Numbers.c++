#include <bits/stdc++.h>
using namespace std;

using ll = long long;
int dp[20][4][2];
string s;

ll solve(int pos, int nonZero, int tight){
    if(pos == s.size()) return 1;

    if(dp[pos][nonZero][tight] != -1) return dp[pos][nonZero][tight];

    int limit = tight ? s[pos]-'0' : 9;
    ll ans = 0;

    for(int d = 0; d <= limit; d++){
        int nextNonZero = nonZero + (d != 0);

        if(nextNonZero > 3) continue;

        int nextTight = tight && (d == limit);

        ans += solve(pos+1, nextNonZero, nextTight);
    }
    return dp[pos][nonZero][tight] = ans;
}
ll f(ll n){
    if(n < 0) return 0;

    s = to_string(n);
    
    memset(dp, -1, sizeof(dp));
    return solve(0, 0, 1);
}

int main(){
    int t;
    cin>>t;
    while(t--){
        ll l, r;
        cin>>l>>r;
        ll ansl = f(l-1), ansr = f(r);
        cout<<ansr - ansl<<'\n';
    }
    return 0;
}