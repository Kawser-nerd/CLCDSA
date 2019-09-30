#include<algorithm>
#include<cmath>
#include<iomanip>
#include<iostream>
#include<map>
#include<numeric>
#include<queue>
#include<set>
#include<sstream>
#include<unordered_map>
#include<unordered_set>
#include<vector>
using namespace std;
using uint = unsigned int;
using ll = long long;
const int M = 1e9 + 7;
const ll MLL = 1e18L + 9;
#pragma unused(M)
#pragma unused(MLL)
#ifdef LOCAL
#include"rprint.hpp"
#else
template <ostream& out = cout, class... T> void prints(T&&...){ }
template <ostream& out = cout, class... T> void printd(T&&...){ }
template <ostream& out = cout, class... T> void printde(T&&...){ }
template <ostream& out = cout, class... T> void printb(T&&...){ }
template <ostream& out = cout, class... T> void printArr(T&&...){ }
#endif

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll x; cin >> x;
    int k; cin >> k;
    unordered_set<int> rs;
    set<int> times;
    for(int i = 0; i < k; i++){
        int r; cin >> r;
        times.insert(r);
        rs.insert(r);
    }
    int q; cin >> q;
    vector<int> as(q);
    vector<pair<int, int>> as2(q);
    unordered_map<int, vector<int>> ts;
    for(int i = 0; i < q; i++){
        int t, a;
        cin >> t >> a;
        as2[i] = {as[i] = a, i};
        times.insert(t);
        ts[t].push_back(i);
    }
    sort(as2.begin(), as2.end());
    int sign = -1, acc = 0, bidx = 0, lidx = q - 1, prev = 0;
    unordered_set<int> lows, highs;
    vector<ll> anss(q);
    ll low = 0, high = x;
    for(int time : times){
        int diff = time - prev;
        prev = time;
        acc += sign * diff;
        low = max(0ll, min(x, low + sign * diff));
        high = max(0ll, min(x, high + sign * diff));
        while(bidx <= lidx && as2[bidx].first + acc <= 0){
            lows.insert(as2[bidx].second);
            printd(lows);
            bidx++;
        }
        while(bidx <= lidx && as2[lidx].first + acc >= x){
            highs.insert(as2[lidx].second);
            lidx--;
        }
        if(ts.count(time)){
            for(int i : ts[time]){
                if(lows.count(i)){
                    anss[i] = low;
                }else if(highs.count(i)){
                    anss[i] = high;
                }else{
                    anss[i] = acc + as[i];
                }
            }
        }
        if(rs.count(time)){
            sign *= -1;
        }
    }
    for(int i = 0; i < q; i++){
        cout << anss[i] << '\n';
    }
    return 0;
}