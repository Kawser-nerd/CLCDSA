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
    ll a,b,c;
    cin>>a>>b>>c;
    if(c==0) {
        pr(b);
        return 0;
    }
    ll sum =1;
    c--;
    while(b>=1 && c>=1){
        sum++;
        sum++;
        b--;
        c--;
    }
    if(b==0) {
        pr(sum+min(a,c));
        return 0;
    }
    pr(sum + b);
    return 0;
}