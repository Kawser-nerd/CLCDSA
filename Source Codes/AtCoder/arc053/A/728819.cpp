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
#define rep(i,n) for(ll i=0;i<n;i++)
#define alll(v) v.begin(),v.end()
#define mp(a,b) make_pair(a,b)
#define rdd(a) ll a; cin>>a
#define rrd rdd(a);rep(i,a)
using namespace std;
template<class X>void pr(X x){cout<<x<<endl;}
template<class X>void prr(X x){for(auto it:x){cout<<it<<endl;}}

int main(){
    rdd(h);
    rdd(w);
    pr(2*(h-1)*(w-1)+w+h-2);
    return 0;
}