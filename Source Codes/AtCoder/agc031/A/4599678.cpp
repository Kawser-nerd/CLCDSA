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
    string s;
    ll n;
    cin>>n;
    cin>>s;
    ll d[26] = {};
    rep(i, n) {
        auto c = s[i];
        auto indx = c - 'a';
        d[indx]++;
    }
    auto sum = 0;
    rep(j, 26){
        auto yy = (sum * d[j]) % 1000000007;
        sum += yy + d[j];
        sum%=1000000007;
    }
    pr(sum);

    return 0;
}