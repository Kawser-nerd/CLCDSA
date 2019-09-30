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
    int n;
    cin>>n;
    vector<ll> v(n+2),c1(n+2),c2(n+2);
    rep(i, n) cin>>v[i+1];
    ll sum =0;
    v[n+1]=0;
    v[0]=0;
    rep(i, n+1) sum+=abs(v[i]-v[i+1]);
    rep(i, n+1) c1[i] = abs(v[i]-v[i+1]);
    rep(i, n) c2[i] = abs(v[i]-v[i+2]);
    rep(i, n-2){
        pr(sum - c1[i]- c1[i+1]+c2[i]);
    }
    pr(sum - c1[n-2]- c1[n-1]+c2[n-2]);
    pr(sum - c1[n-1]- c1[n]+abs(v[n-1]));
}