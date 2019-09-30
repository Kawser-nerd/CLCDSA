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
ll s[12345678];
ll v[12345678];
ll keta(ll a){
    ll res = 0;
    while(a){
        res += a%10;
        a/=10;
    }
    return res;
}
bool comp(ll a,ll b){
    ll ka = keta(a);
    ll kb = keta(b);
    if(a*kb == b*ka)return a<b;
    else return a*kb<b*ka;
}
int main(){
    ll ten[17];
    ten[0] = 1;
    rep(i,16)ten[i+1] = ten[i]*10;
    vector<ll>ans;
    rep(i,17){
        rep(j,999){
            if((j+1)*ten[i]>1e15)break;
            ans.push_back((ll)(j+1)*ten[i]-1);
        }
    }
    sort(ans.begin(),ans.end(),comp);
    vector<ll>a;
    ll ma = 0;
    for(ll x:ans){
        if(ma<x)a.push_back(x);
        ma = max(x,ma);
    }
    int k;
    cin >> k;
    rep(i,k)cout << a[i] << endl;
}