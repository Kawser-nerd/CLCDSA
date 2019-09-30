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
//1,2,...,a?b?????c??
ll f(ll a, ll b, ll c){
    if(c< b)return min(a,c);
    else return min(a,c+1);
}
//a,a-1,...,1?b?????c??
ll g(ll a, ll b, ll c){
    ll res = a-c+1;
    if(b>a or res>b)return max(1LL,res);
    else return max(1LL,res-1);
}
int main(){
    int q;
    cin >> q;
    while(q--){
        ll a,b;
        cin >>a >> b;
        show(a*b);
        ll l = 0;
        ll r = 1LL<<31;
        while(r-l>1){
            ll mid = (l+r)/2;
            ll x = (mid+1)/2;
            ll ma = 0;
            if(x-1>=1)ma = max(ma, f(mid,a,x-1)*g(mid,b,x-1));
            ma = max(ma, f(mid,a,x)*g(mid,b,x));
            ma = max(ma, f(mid,a,x+1)*g(mid,b,x+1));
            show(mid);
            show(ma);
            if(ma >= a*b){
                r = mid;
            }else{
                l = mid;
            }
        }
        {
            ll ma = 0;
            ll n = l;
            ll m = l;
            if(a<=n)n++;
            if(b<=m)m++;
            ll x = (n+1)/2;
            if(x-1>=1)ma = max(ma, f(n,a,x-1)*g(m,b,x-1));
            ma = max(ma, f(n,a,x)*g(m,b,x));
            ma = max(ma, f(n,a,x+1)*g(m,b,x+1));
            if(ma >= a*b)l--;
        }
        cout << l << endl;
    }
}