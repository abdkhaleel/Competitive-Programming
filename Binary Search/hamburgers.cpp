#include<bits/stdc++.h>
using namespace std;

tuple<int, int, int> count(string recipe){
    int cb = 0;
    int cs = 0;
    int cc = 0;
    for(char& c: recipe){
        if(c == 'B') cb++;
        else if(c == 'S') cs++;
        else cc++;
    }
    return {cb, cs, cc};
}
tuple<int, int, int> extract(vector<int> v){
    return {v[0], v[1], v[2]};
}
int64_t hamburgers(string recipe, vector<int> kitchenItems, vector<int> prices, int64_t rubles){
    auto [cb, cs, cc] = count(recipe);
    auto [pb, ps, pc] = extract(prices);
    auto [nb, ns, nc] = extract(kitchenItems);
    int64_t low = 0;
    int64_t high = 2e12;

    auto canMake = [&](int64_t x) -> bool {
        int64_t need_b = cb * x;
        int64_t need_s = cs * x;
        int64_t need_c = cc * x;

        int64_t buy_b = max(0LL, need_b - nb);
        int64_t buy_s = max(0LL, need_s - ns);
        int64_t buy_c = max(0LL, need_c - nc);

        int64_t cost = buy_b * pb + buy_s * ps + buy_c * pc;

        return cost <= rubles;
    };
    while(low < high){
        int64_t mid = low + (high - low + 1) / 2;
        if(canMake(mid)){
            low = mid;
        }
        else{
            high = mid-1;
        }
    }
    return low;
}
int main(){
    string recipe;
    cin>>recipe;
    vector<int> kitchenItems(3);
    for(int i = 0; i < 3; i++) cin>>kitchenItems[i];
    vector<int> prices(3);
    for(int i = 0; i < 3; i++) cin>>prices[i];
    int64_t rubles;
    cin>>rubles;
    int64_t ans = hamburgers(recipe, kitchenItems, prices, rubles);
    cout<<ans;
    return 0;
}