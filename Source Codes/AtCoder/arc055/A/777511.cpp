#include <iostream>
#include <iomanip>
#include <cstdio>
#include <algorithm>
#include <math.h>
#include <map>
#include <unordered_map>
#include <set>
#include <deque>
#include <vector>
#include <stack>
#include <queue>
#define ll long long
#define vi vector<int>
#define vvi vector<vector<int>>
#define vs vector<string>
#define fr(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)
#define alll(v) v.begin(),v.end()
#define mp(a,b) make_pair(a,b)
#define rdd(a) int a; cin>>a
#define rrd rdd(a);rep(i,a)
using namespace std;
template<class X>void pr(X x){cout<<x<<endl;}
template<class X>void prr(X x){for(auto it:x){cout<<it<<endl;}}

int main(){
    ll n;
    cin>>n;
    cout<<"1";
    rep(i, n-1) cout<<"0";
    cout<<"7"<<endl;
    return 0;
}