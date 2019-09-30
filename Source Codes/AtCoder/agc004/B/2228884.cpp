#include <algorithm>
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
#define show(x) cout << #x << " = " << x << endl;
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int main(){
    int n;
    ll x;
    cin >> n >> x;
    ll a[2005];
    ll b[2005];
    rep(i,n){
        cin >> a[i];
        b[i] = a[i];
    }
    ll ans = 1LL << 60;
    rep(num,n){
        ll temp = x*num;
        rep(i,n){
            b[i] = min(b[i],a[(i-num+n)%n]);
            temp+=b[i];
        }
        ans = min(ans,temp);
    }
    cout << ans << endl;
}