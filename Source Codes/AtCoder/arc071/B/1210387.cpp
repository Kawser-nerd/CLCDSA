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
    int n, m;
    cin >> n >> m;
    vector<ll> xs(n), ys(m);
    for(int i=0;i<n;i++){
        cin >> xs[i];
    }
    for(int i=0;i<m;i++){
        cin >> ys[i];
    }
    sort(xs.begin(), xs.end());
    sort(ys.begin(), ys.end());
    ll numx = 0, numy = 0;
    vector<ll> numsx(n), numsy(m);
    for(int i=1;i<n;i++){
        numsx[i] = (xs[i] - xs[i - 1]) * i + numsx[i - 1];
    }
    for(int i=1;i<m;i++){
        numsy[i] = (ys[i] - ys[i - 1]) * i + numsy[i - 1];
    }
    ll accx = 0, accy = 0;
    for(int i=0;i<n;i++){
        accx = (accx + numsx[i]) % M;
    }
    for(int i=0;i<m;i++){
        accy = (accy + numsy[i]) % M;
    }
    cout << (accx * accy) % M << '\n';
    return 0;
    // ll basex = xs.back() - xs.front(), basey = ys.back() - ys.front();
    // ll base = basex * basey;
    // // ll remx = base, remy = base, prevx = xs.front(), prevy = ys.front();
    // ll remx = 0, remy = base, prevx = xs.front(), prevy = ys.front();
    // ll ans = base;
    // for(int i=1;i<max(n-1, m-1);i++){
    //     if(i < xs.size()){
    //         ans = (ans + base) % M;
    //         ans = (ans + remx) % M;
    //         remx = basey * (xs.back() - xs[i]) % M;
    //     }
    //     if(i < ys.size()){
    //         ans = (ans + base) % M;
    //         ans = (ans + remy) % M;
    //         remy = basex * (ys.back() - ys[i]) % M;
    //     }
    // }
    // cout << ans << '\n';
    // return 0;
}