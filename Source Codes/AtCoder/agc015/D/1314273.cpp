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

ll solve(ll a, ll b){
    int msba, msbb;
    ll a2 = a, b2 = b;
    while(1){
        msba = msbb = -1;
        for(int i = 0; i < 64; i++){
            if(a2 & (1ll << i)){ msba = i; }
            if(b2 & (1ll << i)){ msbb = i; }
        }
        if(msba != msbb){ break; }
        a2 ^= 1ll << msba;
        b2 ^= 1ll << msba;
    }
    prints(msba, msbb);
    ll upper = (1ll << msbb) - a2;
    // ll upper2 = (1ll << msbb) * 2 - upper;
    ll upper2 = (1ll << msbb) | a2;
    ll range1 = b2 - a2 + 1,
       dupe = max(0ll, b2 - upper2 + 1);
    printd(upper, upper2, range1, dupe);
    bitset<64> bsu(upper2), bsa(a), bsb(b), bs1(range1 + upper - dupe), bs2(68833183630578410ll);
    printd(bsu);
    printd(bsa);
    printd(bsb);
    printd(bs1);
    printd(bs2);
    // cout << range1 + upper - dupe << '\n';
    int msbb2 = 0;
    for(int i = 0; i < 64; i++){
        if((b2 ^ (1ll << msbb)) & (1ll << i)){ msbb2 = i; }
    }
    ll lower = b2 | ((1ll << msbb2) - 1);
    bitset<64> bsl(lower);
    printd(bsl);
    range1 = lower - a2 + 1;
    dupe = max(0ll, lower - upper2 + 1);
    return range1 + upper - dupe;
}

int main(){
    ll a, b;
    cin >> a >> b;
    if(a == b){ cout << 1 << '\n'; return 0; }
    cout << solve(a, b) << '\n';
    return 0;
}