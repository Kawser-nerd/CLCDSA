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
    ll n;
    cin>>n;
    vector<ll> v;
    rep(i, n) {
        ll y;
        cin>>y;
        if(i == 0) v.push_back(y);
        else{
            if(v.back() != y) v.push_back(y);
        }
    }
    unordered_map<ll, ll> m;
    vector<ll> ans(v.size(), 0);
    rep(i, v.size()) {
        auto arg = v[i];
    
        if(i==0) {
            m[arg] = i+1;
            continue;
        }
        ans[i] = ans[i-1];
        if(m[arg] > 0){
            ll y = (ans[m[arg]-1] +1) % 1000000007;
            ans[i] += y;
            ans[i] %= 1000000007;
        }
        m[arg] = i+1;
    }
    pr( (ans[v.size() -1] + 1) % 1000000007 );



    return 0;
}