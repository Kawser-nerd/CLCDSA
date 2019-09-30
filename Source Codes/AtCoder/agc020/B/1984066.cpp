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
#include"debug_deque.hpp"
#define vector DebugDeque
#else
#define FUNC(name) template <ostream& out = cout, class... T> void name(T&&...){ }
FUNC(prints) FUNC(printe) FUNC(printw) FUNC(printew) FUNC(printb) FUNC(printd) FUNC(printde);
#endif

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int k; cin >> k;
    vector<int> as(k);
    for(int i = 0; i < k; i++){
        cin >> as[i];
    }
    ll l = 0, r = 1e18;
    while(l + 1 < r){
        ll piv = (l + r) / 2, num = piv;
        for(int i = 0; i < k; i++){
            num = num / as[i] * as[i];
        }
        if(num == 2){
            l = piv;
        }else if(num < 2){
            l = piv + 1;
        }else{
            r = piv;
        }
        printd(l, r);
    }
    ll maxi = l;
    l = 0, r = maxi;
    while(l + 1 < r){
        ll piv = (l + r) / 2, num = piv;
        for(int i = 0; i < k; i++){
            num = num / as[i] * as[i];
        }
        if(num == 2){
            r = piv;
        }else{
            l = piv;
        }
        printd(l, r);
    }
    ll mini = r;
    ll mi2 = mini, ma2 = maxi;
    for(int i = 0; i < k; i++){
        mi2 = mi2 / as[i] * as[i];
        ma2 = ma2 / as[i] * as[i];
    }
    if(mi2 != 2 || ma2 != 2){
        cout << -1 << '\n';
    }else{
        cout << mini << ' ' << maxi << '\n';
    }
}