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
int n;
ll a,b;
vector<ll>h;
bool ok(ll t){//t???????
    ll cnt = 0;
    rep(i,n){
        if(h[i]-b*t>0){
            cnt+=(h[i]-t*b+a-b-1)/(a-b);
        }
    }
    return cnt<=t;
}
int main(){
    cin >> n >> a >> b;
    h.resize(n);
    rep(i,n){
        cin >> h[i];
    }
    ll l = 0;
    ll r = 1000000004;
    while(r-l>1){
        ll mid = (l+r)/2;
        if(ok(mid)){
            r = mid;
        }else{
            l = mid;
        }
    }
    cout << r << endl;
    
}