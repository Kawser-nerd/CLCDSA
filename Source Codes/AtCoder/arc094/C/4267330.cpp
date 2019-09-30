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
#include <bitset>
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define show(x) cout << #x << " = " << (x) << endl;
using namespace std;
using ll = long long;
using pii = pair<int,int>;
int main(){
    int n;
    cin >> n;
    vector<ll>a(n),b(n);
    rep(i,n)cin >> a[i] >> b[i];
    if(a==b)return cout << 0 << endl, 0;
    ll sum = accumulate(a.begin(),a.end(),0LL);
    ll mi = 1LL<<60;
    rep(i,n)if(a[i]>b[i])mi=min(mi,b[i]);
    cout << sum - mi << endl;
}