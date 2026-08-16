#include <bits/stdc++.h>
using namespace std;

int solve(string s){
    int n = s.size();
    int q = 0;
    for(int i = 0; i < n; i++) if(s[i] == 'Q') q++;
    int runningQ = 0;
    int ans = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == 'Q') runningQ++;
        else if(s[i] == 'A'){
            ans += runningQ * (q - runningQ);
        }
    }
    return ans;
}

int main(){
    string s;
    cin>>s;
    int ans = solve(s);
    cout<<ans<<'\n';
    return 0;
}