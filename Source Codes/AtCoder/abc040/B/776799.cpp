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
    rdd(n);
    int x = sqrt(double(n));
    int yy= n;
    for(int i = 1;i<=x;i++){
        
        int y = n%i;
        int z = n/i;
        yy=min(yy,abs(i-z)+y);
    }
    pr(yy);
    return 0;
}