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
using ll = long long;
using pii = pair<int,int>;
ll mergecount(vector<ll> &a) {
    ll count = 0;
    int n = (int)a.size();
    if (n > 1) {
        vector<ll> b(a.begin(), a.begin() + n/2);
        vector<ll> c(a.begin() + n/2, a.end());
        count += mergecount(b);
        count += mergecount(c);
        for (int i = 0, j = 0, k = 0; i < n; ++i)
            if (k == c.size())       a[i] = b[j++];
            else if (j == b.size())  a[i] = c[k++];
            else if (b[j] <= c[k])   a[i] = b[j++];
            else                   { a[i] = c[k++]; count += n/2 - j; }
    }
    return count;
}
int main(){
    int n;
    ll k;
    scanf("%d %lld",&n,&k);
    vector<ll>a(n);
    vector<ll>b(n+1);
    b[0] = 0;
    rep(i,n){
        scanf("%lld",&a[i]);
        b[i+1] = a[i] - k + b[i];
    }
    ll N = (ll)n;
    cout << (ll)N*(N+1)/2 -mergecount(b) << endl;
}