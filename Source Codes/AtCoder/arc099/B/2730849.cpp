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
    ll k;
    cin>>k;
    vector<ll> v,vv;
    rep(i,1000){
        v.push_back(i);
    }
    ll y = 1;
    rep(p, 15){
        for(auto it:v){
            vv.push_back(it*y + (y-1));
        }
        y*=10;
    }
    sort(alll(vv));
    vv.erase(std::unique(alll(vv)), vv.end());
    sort(alll(vv));
    double g = 1000000000000001;
    vector<ll> vvv;
    rep(i, vv.size()){
        ll tmp = vv[vv.size()-1-i];
        string s = to_string(tmp);
        ll summer = 0;
        rep(j, s.size()) summer+=(s[j]-'0');//?
        double aaa = ((double) tmp )/((double) summer);
//        pr(aaa);
//        pr(tmp);
//        pr(g);
//        pr("");
//        pr(s);
//        pr(s[0]);
//        pr((ll)s[0]);
        if(aaa <= g){
            g=aaa;
            vvv.push_back(tmp);
        }
    }
//    for x in range(100000009,0,-1):
//        s = str(x)
//        t = x/sum([int(y) for y in list(s)])
//        if(t <= g):
//            g = min(g,t)
//            print(s,g,t,sep='\t')
//
//    pr(vvv.size());
    sort(alll(vvv));
//    unique(alll(vvv));
    rep(i, k) pr(vvv[i]);
    
    
}