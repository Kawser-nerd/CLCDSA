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
    cin >> n;
    vector<ll>a(n+2);
    rep(i,n){
        cin >> a[i+1];
    }
    a[0] = 0;
    a[n+1] = 0;
    ll t = 0;
    rep(i,n+1){
        t += abs(a[i]-a[i+1]);
    }
    rep(j,n){
        int i = j+1;
        cout << t +abs(a[i-1]-a[i+1]) - abs(a[i]-a[i-1]) -abs(a[i]-a[i+1]) << endl;
    }
}