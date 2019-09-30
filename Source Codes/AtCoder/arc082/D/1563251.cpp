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
    vector<ll> rs(k);
    for(int i = 0; i < k; i++){
        cin >> rs[i];
    }
    int q; cin >> q;
    vector<ll> ts(q), as(q);
    vector<pair<int, int>> ti(q);
    vector<pair<ll, int>> ais(q);
    ll low = 0, high = x;
    unordered_set<ll> lows, highs;
    for(int i = 0; i < q; i++){
        cin >> ts[i] >> as[i];
        ais[i] = {as[i], i};
        ti[i] = {ts[i], i};
    }
    sort(ti.begin(), ti.end());
    sort(ais.begin(), ais.end());
    ll ridx = 0, tidx = 0, prev = 0, sign = -1, acc = 0;
    int aidxb = 0, aidxl = q - 1;
    vector<ll> anss(q);
    printd(ais);
    while(tidx < q){
        while(ridx < k && rs[ridx] <= ti[tidx].first){
            ll diff = rs[ridx] - prev;
            prev = rs[ridx];
            acc += sign * diff;
            if(sign == -1){
                low = max(0ll, low - diff);
                high = max(0ll, high - diff);
                while(aidxb <= aidxl && ais[aidxb].first + acc <= 0){
                    lows.insert(ais[aidxb].second);
                    aidxb++;
                }
            }else{
                low = min(x, low + diff);
                high = min(x, high + diff);
                while(aidxb <= aidxl && ais[aidxl].first + acc >= x){
                    highs.insert(ais[aidxl].second);
                    aidxl--;
                }
            }
            sign *= -1;
            ridx++;
        }
        while(tidx < q && (ridx >= k ||  rs[ridx] >= ti[tidx].first)){
            ll diff = ti[tidx].first - prev;
            prev = ti[tidx].first;
            acc += sign * diff;
            if(sign == -1){
                low = max(0ll, low - diff);
                high = max(0ll, high - diff);
                while(aidxb <= aidxl && ais[aidxb].first + acc <= 0){
                    lows.insert(ais[aidxb].second);
                    aidxb++;
                }
            }else{
                low = min(x, low + diff);
                high = min(x, high + diff);
                while(aidxb <= aidxl && ais[aidxl].first + acc >= x){
                    highs.insert(ais[aidxl].second);
                    aidxl--;
                }
            }
            int t = ti[tidx].second;
            if(lows.count(t)){
                anss[t] = low;
            }else if(highs.count(t)){
                anss[t] = high;
            }else{
                anss[t] = as[t] + acc;
            }
            tidx++;
        }
    }
    for(int i = 0; i < q; i++){
        cout << anss[i] << '\n';
    }
    return 0;
}