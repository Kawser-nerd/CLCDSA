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
#include"basic.hpp"
#else
template <class... T> void printl(T&&...){ }
template <class... T> void printc(T&&...){ }
template <class... T> void prints(T&&...){ }
#endif

int main(){
    int i, o, j, l, dump;
    cin >> i >> o >> dump >> j >> l >> dump >> dump;
    ll ans = 0ll + o + i / 2 * 2 + j / 2 * 2 + l / 2 * 2 + (i % 2 && j % 2 && l % 2 ? 3 : 0);
    if(i && j && l){
        ans = max(ans, 0ll + o + 3 + (i - 1) / 2 * 2 + (j - 1) / 2 * 2 + (l - 1) / 2 * 2);
    }
    cout << ans << '\n';
    return 0;
}