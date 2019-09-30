#include<algorithm>
#include<cmath>
#include<iomanip>
#include<iostream>
#include<map>
#include<numeric>
#include<queue>
#include<set>
#include<sstream>
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
template <class... T> void printl(T&&...){ }
template <class... T> void printc(T&&...){ }
template <class... T> void prints(T&&...){ }
template <class... T> void printd(T&&...){ }
template <class... T> void printArr(T&&...){ }
#endif

ll func(ll h, ll w){
    ll ans = MLL;
    for(int i = 1; i < h; i++){
        ll h2 = h - i;
        ll s1 = w * i;
        for(int j = max(1ll, h2 / 2 - 3); j < min(h2, h2 / 2 + 3); j++){
            ll s2 = w * j;
            ll s3 = w * (h2 - j);
            ans = min(ans, max({s1, s2, s3}) - min({s1, s2, s3}));
        }
        for(int j = max(1ll, w / 2 - 3); j < min(w, w / 2 + 3); j++){
            ll s2 = h2 * j;
            ll s3 = h2 * (w - j);
            ans = min(ans, max({s1, s2, s3}) - min({s1, s2, s3}));
        }
    }
    return ans;
}

int main(){
    ll h, w;
    cin >> h >> w;
    ll ans = MLL;
    ans = min(ans, func(h, w));
    ans = min(ans, func(w, h));
    cout << ans << '\n';
    return 0;
}