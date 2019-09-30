#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>
#include <map>
#include <list>
#include <stack>
#include <queue>
#include <utility>
#include <algorithm>
#include <functional>
#include <cassert>

#define REP(i,n) for(int i=0;i<n;i++)

using namespace std;
typedef long long ll;
typedef unsigned long ul;
typedef pair<ul, ul> P;

int main() {
    int n;
    ll x;
    cin >> n >> x;
    vector<ll> a(n);
    for (auto &c : a) cin >> c;
    vector<ll> b = a;
    ll ans = 1e18;

    REP(i,n){
        REP(j,n){
            b[j] = min(b[j], a[(j-i+n)%n]);
        }
        ll buf = x*i;
        REP(j,n){
            buf += b[j];
        }

        ans = min(ans, buf);
    }
    cout << ans << endl;

}