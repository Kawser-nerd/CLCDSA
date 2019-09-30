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
    int n, k;
    cin >> n >> k;
    vector<int> as(n);
    for(int i=0;i<n;i++){
        cin >> as[i];
    }
    ll block = 0;
    for(int i=0;i<k;i++){
        block += as[i];
    }
    ll lsum = 0, rsum = 0;
    for(int i=k;i<n;i++){
        rsum += max(0, as[i]);
    }
    ll ans = lsum + max(block, 0ll) + rsum;
    for(int i=k;i<n;i++){
        block += as[i];
        block -= as[i - k];
        lsum += max(0, as[i - k]);
        rsum -= max(0, as[i]);
        ans = max(ans, lsum + max(block, 0ll) + rsum);
    }
    cout << ans << '\n';
    return 0;
}