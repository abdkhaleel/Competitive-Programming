#include <bits/stdc++.h>
using namespace std;

int find_k(vector<int> &arr, int n) {
    int mini = 1e9, maxi = -1e9;
    for(int i = 0; i < n; i++) {
        mini = min(mini, arr[i]);
        maxi = max(maxi, arr[i]);
    }
    return maxi - mini + 1;
}

void start_case() {
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin>>arr[i];
    }
    int k = find_k(arr, n);
    cout<<k<<endl;
}

int main() {
    int t;
    cin>>t;
    while(t--){
        start_case();
    }
    return 0;
}