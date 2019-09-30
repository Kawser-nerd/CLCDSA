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
    ll a,b,c;
    vector<ll> v;
    cin>>a>>b>>c;
    if (b<a) {
        swap(a, b);
    }
    if (c<b) {
        swap(c, b);
    }
    if (b<a) {
        swap(a, b);
    }
    ll t = c-a;
    ll r = c-b;
    ll sum=0;
    sum+=t/2;
    t=t%2;
    sum+=r/2;
    r=r%2;
    if (r==0 && t == 0) {
        pr(sum);
    }else if (r==1 && t==1){
        pr(sum+1);
    }else pr(sum+2);
}