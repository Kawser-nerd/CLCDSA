#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstring>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <vector>
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define show(x) //cout << #x << " = " << (x) << endl;
using namespace std;
using ll = long long;
using pii = pair<int,int>;
int main(){
    ll n,k;
    cin >> n >> k;
    ll ans = 0;
    for(ll b = k+1; b <= n; b++){
        ll num = n/b;
        ans += num*(b-k);
        ll amari = n%b;
        ans += max(0LL,amari-k+1);
    }
    if(k==0)ans-=n;
    cout << ans << endl;
}