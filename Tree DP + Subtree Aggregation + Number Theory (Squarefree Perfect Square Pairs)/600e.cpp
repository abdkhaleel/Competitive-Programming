#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> colors_;
vector<vector<int>> tree_;
vector<long long> dominatingColors;
vector<int> cnt_;
int curMax;
long long curSum;
vector<int> subSz;

void add(int u, int par, int val){
    cnt_[colors_[u]] += val;
    if(cnt_[colors_[u]] > curMax){
        curMax = cnt_[colors_[u]];
        curSum = colors_[u];
    } else if(cnt_[colors_[u]] == curMax){
        curSum += colors_[u];
    }
    for(int v : tree_[u]) if(v != par) add(v, u, val);
}

void calcSize(int u, int par){
    subSz[u] = 1;
    for(int v : tree_[u]) if(v != par){
        calcSize(v, u);
        subSz[u] += subSz[v];
    }
}

void dfs(int u, int par, bool keep){
    int bigChild = -1, bigSize = -1;
    for(int v : tree_[u]) if(v != par && subSz[v] > bigSize){
        bigSize = subSz[v];
        bigChild = v;
    }

    // process light children first, discard their contribution
    for(int v : tree_[u]) if(v != par && v != bigChild){
        dfs(v, u, false);
    }

    // process heavy child, keep its contribution
    if(bigChild != -1) dfs(bigChild, u, true);

    // add u itself and all light children's subtrees
    cnt_[colors_[u]]++;
    if(cnt_[colors_[u]] > curMax){ curMax = cnt_[colors_[u]]; curSum = colors_[u]; }
    else if(cnt_[colors_[u]] == curMax){ curSum += colors_[u]; }

    for(int v : tree_[u]) if(v != par && v != bigChild){
        add(v, u, 1);
    }

    dominatingColors[u] = curSum;

    if(!keep){
        // remove everything in u's subtree to reset global state
        add(u, par, -1);
        curMax = 0;
        curSum = 0;
    }
}

void solve(){
    cin >> n;
    colors_.resize(n);
    tree_.assign(n, {});
    dominatingColors.assign(n, 0);
    cnt_.assign(n + 1, 0);
    subSz.assign(n, 0);

    for(int i = 0; i < n; i++) cin >> colors_[i];

    for(int i = 1; i < n; i++){
        int u, v; cin >> u >> v; u--; v--;
        tree_[u].push_back(v);
        tree_[v].push_back(u);
    }

    calcSize(0, -1);
    dfs(0, -1, true);

    for(long long x : dominatingColors) cout << x << " ";
    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // run on a thread with a larger stack to be safe against deep/skewed trees
    std::thread t([](){ solve(); });
    t.join();
    return 0;
}