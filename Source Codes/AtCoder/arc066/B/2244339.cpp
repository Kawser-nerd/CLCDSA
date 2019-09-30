#include <algorithm>
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstring>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <vector>
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define show(x) cout << #x << " = " << x << endl;
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
ll mod = 1000000007;
map<pair<ll,ll>,ll>dp;
ll cal(ll x,ll y){
    if(x < 0 or y < 0)return 0;
    if(dp[{x,y}]){
        return dp[{x,y}];
    }
    ll res = cal(x/2,y/2);
    if(x>=1 and y>=1)res+=cal((x-1)/2,(y-1)/2);
    if(x>=2)res+= cal((x-2)/2,y/2);
    return dp[{x,y}] = res%mod;
}
int main(){
    ll n;
    cin >> n;
    dp[{0,0}] = 1;
    cout << cal(n,n) << endl;
}