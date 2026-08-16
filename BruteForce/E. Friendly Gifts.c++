#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> a(n);
        for(auto& x : a) cin >> x;

        // ── Step 1: Precompute mn[i][l] ──────────────────────────────────────
        // mn[i][l] = min value of a[i..i+l-1] if it's a good subarray, else -1
        // Good = no duplicates AND max - min + 1 == length
        // O(n^2)
        vector<vector<int>> mn(n, vector<int>(n/2 + 1, -1));
        vector<int> freq(n + 2, 0);

        for(int i = 0; i < n; i++){
            fill(freq.begin(), freq.end(), 0);
            int lo = a[i], hi = a[i], dups = 0;
            freq[a[i]]++;
            for(int j = i; j < n; j++){
                if(j > i){
                    freq[a[j]]++;
                    if(freq[a[j]] == 2) dups++;
                    lo = min(lo, a[j]);
                    hi = max(hi, a[j]);
                }
                int l = j - i + 1;
                // Only need lengths up to n/2 (need room for two segments)
                if(l <= n/2 && dups == 0 && hi - lo + 1 == l)
                    mn[i][l] = lo;
            }
        }

        // ── Step 2: For each L, sweep with DP ────────────────────────────────
        int ans = 0;

        for(int L = 1; L <= n/2; L++){
            // seen[mv] = true if a good segment of length L with min=mv
            //            exists at start index s where s + L <= current i
            vector<bool> seen(n + 2, false);

            for(int i = 0; i <= n - L; i++){
                // Add the segment starting at (i - L): it ends at i-1
                // so it is ADJACENT (non-overlapping) with segment at i
                if(i >= L && mn[i - L][L] != -1)
                    seen[ mn[i - L][L] ] = true;

                // Try current segment as the RIGHT segment
                if(mn[i][L] != -1){
                    int mv = mn[i][L];
                    // Check both orderings of concatenation
                    if(mv + L <= n     && seen[mv + L]) ans = max(ans, L);
                    if(mv - L >= 1     && seen[mv - L]) ans = max(ans, L);
                }
            }
        }

        cout << ans << "\n";
    }
}