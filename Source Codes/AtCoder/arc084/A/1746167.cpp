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
using uint = unsigned int;
using ll = long long;
enum : int { M = (int)1e9 + 7 };
enum : ll { MLL = (ll)1e18L + 9 };
using namespace std;
#ifdef LOCAL
#include"rprint2.hpp"
#else
#define FUNC(name) template <ostream& out = cout, class... T> void name(T&&...){ }
FUNC(prints) FUNC(printe) FUNC(printw) FUNC(printew) FUNC(printb) FUNC(printd) FUNC(printde);
#endif

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n; cin >> n;
    vector<int> as(n), bs(n), cs(n);
    for(int i = 0; i < n; i++){ cin >> as[i]; }
    for(int i = 0; i < n; i++){ cin >> bs[i]; }
    for(int i = 0; i < n; i++){ cin >> cs[i]; }
    sort(as.begin(), as.end());
    sort(bs.begin(), bs.end());
    sort(cs.begin(), cs.end());
    prints(as, bs, cs);
    vector<ll> b2;
    for(int i = 0; i < n; i++){
        int b = bs[i];
        b2.push_back(cs.end() - upper_bound(cs.begin(), cs.end(), b));
    }
    prints(b2);
    for(int i = n - 2; i >= 0; i--){
        b2[i] += b2[i + 1];
    }
    ll ans = 0;
    for(int i = 0; i < n; i++){
        int a = as[i];
        int bi = upper_bound(bs.begin(), bs.end(), a) - bs.begin();
        prints(bi);
        if(bi < n){
            ans += b2[bi];
        }
    }
    cout << ans << '\n';
}