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
int main(){
    int n;
    cin >> n;
    vector<ll>a(n);
    vector<ll>b(n);
    vector<ll>c(n);
    rep(i,n){
        scanf("%lld",&a[i]);
        if(i==0){
            b[i] = a[i];
            c[i] = a[i];
        }else{
            b[i] = b[i-1]+a[i];
            c[i] = c[i-1]^a[i];
        }
    }
    ll ans = 0;
    rep(i,n){
        int l = i;
        int r = n;
        while(r-l>1){
            int mid = (l+r)/2;
            ll k = b[mid];
            if(i)k-=b[i-1];
            ll kk = c[mid];
            if(i)kk^=c[i-1];
            if(k==kk){
                l = mid;
            }else{
                r = mid;
            }
        }
        ans += l-i+1;
    }
    cout << ans << endl;
}