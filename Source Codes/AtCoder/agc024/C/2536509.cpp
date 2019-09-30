#include <iostream>
#include <vector>
#include <cstdio>
#include <queue>
#include <algorithm>
#include <functional>
#include <string>
#include <queue>
#include <cmath>
#include <iomanip>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <random>
#include <unordered_map>
#include <unordered_set>
#define ll long long
#define fr(i,k,N) for(ll i=k; i<N;i++)
#define rep(i,N) for(ll i=0; i<N;i++)
#define alll(v) v.begin(),v.end()
using namespace std;
template <class X> void pr(X test){cout<<test<<endl;}
template <class X> void prr(X test){for(auto it:test){cout<<it;}cout<<endl;}


int main() {
    ll n;
    cin>>n;
    vector<ll> v(n,0),m(n,0);
    ll tmp;
    ll count =0;
    rep(i, n) cin>>m[i];
    reverse(alll(m));
    ll lasttmp=0;
    rep(i, n) {
        tmp=m[i];
        if(tmp < lasttmp - 1){
            pr(-1);
            return 0;
        }
        if(tmp == lasttmp-1) {
            lasttmp=tmp;
            continue;
        }
        else {
            count+=tmp;
            lasttmp=tmp;
        }
    };
    if(lasttmp != 0) pr(-1);
    else pr(count);
}