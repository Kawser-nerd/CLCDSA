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
    int n, a, b;
    cin >> n >> a >> b;
    int prev; cin >> prev;
    ll ans = 0;
    for(int i=1;i<n;i++){
        ll x; cin >> x;
        ll c = (x - prev) * a;
        if(c < b){
            ans += c;
        }else{
            ans += b;
        }
        prev = x;
    }
    cout << ans << '\n';
    return 0;
}