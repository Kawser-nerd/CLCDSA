#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
#include <iomanip>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <algorithm>
#include <random>
#include <unordered_map>
#define ll long long
#define fr(i,k,N) for(ll i=k; i<N;i++)
#define rep(i,N) for(ll i=0; i<N;i++)
#define alll(v) v.begin(),v.end()
using namespace std;
template <class X> void pr(X test){cout<<test<<endl;}
template <class X> void prr(X test){for(auto it:test){cout<<it;}cout<<endl;}

int main(){
    ll n,m;
//    string s;
    cin >> n>>m;
//    vector<ll> vl;
//    vector<string> vs;
//    rep(i, n) cin >>;
    ll sum = 0;
    if (n==1 and m==1) {
        sum=1;
    }else if (n==1){
        sum = m-2;
    }else if(m==1){
        sum=n-2;
    }else {
        ll a = (m-2)*(n-2);
        ll b = 2*m+2*n-8;
        ll c =4;
        sum=a;
    }
    pr(sum);
    return 0;
}