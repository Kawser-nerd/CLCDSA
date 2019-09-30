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
#endif

int main(){
    int n; cin >> n;
    vector<pair<int, int>> as(n);
    for(int i=0;i<n;i++){
        cin >> as[i].first;
        as[i].second = i;
    }
    sort(as.begin(), as.end());
    vector<ll> ans(n);
    int maxPos = M, w = 1;
    for(int i=n-1;i>=0;i--){
        maxPos = min(maxPos, as[i].second);
        int d = as[i].first - (i ? as[i-1].first : 0);
        ans[maxPos] += 1ll * d * w;
        w++;
    }
    for(int i=0;i<n;i++){
        cout << ans[i] << '\n';
    }
    return 0;
}