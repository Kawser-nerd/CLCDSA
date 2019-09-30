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
#define ll long long
#define fr(i,k,N) for(ll i=k; i<N;i++)
#define rep(i,N) for(ll i=0; i<N;i++)
#define alll(v) v.begin(),v.end()
using namespace std;
template <class X> void pr(X test){cout<<test<<endl;}
template <class X> void prr(X test){for(auto it:test){cout<<it;}cout<<endl;}

int main() {
    ll q;
    cin>>q;
    vector<ll> v(q),v2(q);
    rep(i, q){
        ll tmp;
        cin>>tmp;
        v[i]=tmp;
        v2[i]=tmp;
    }
    sort(alll(v));
    ll mid1 = v[v.size()/2-1];
    ll mid2 = v[v.size()/2];
    rep(i, q){
        if (v2[i] <= mid1) {
            pr(mid2);
        }else pr(mid1);
    }
    
}