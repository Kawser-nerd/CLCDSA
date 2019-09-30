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
template <class X> void prr(X test){for(auto it:test){cout<<it<<endl;}cout<<endl;}

int main() {
    ll n,m,c;
    cin >>n>>m>>c;
    vector<ll> b;
    rep(i, m){
        ll bb ;
        cin>>bb;
        b.push_back(bb);
    }
    ll sum=0;
    rep(i, n){
        vector<ll> a;
        rep(i, m){
            ll bb ;
            cin>>bb;
            a.push_back(bb);
        }
        auto in = inner_product(
        a.begin(), a.end(),
        b.begin(),
        c);
        if(in > 0) sum++;
    }
    pr(sum);
    return 0;
}