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
using ll = long long;
using pii = pair<int,int>;
map<int,ll>mp;
int d[123456];
vector<pii>g[123456];
void dfs(int s){
    for(auto &x:g[s]){
        if(d[x.first]==-1){
            d[x.first] = d[s]^x.second;
            dfs(x.first);
        }
    }
}
int main(){
    int n,x;
    cin >> n >> x;
    rep(i,n-1){
        int a,b,c;
        cin >> a >> b >> c;
        a--,b--;
        g[a].push_back(pii(b,c));
        g[b].push_back(pii(a,c));
    }
    memset(d,-1,sizeof(d));
    d[0] = 0;
    dfs(0);
    rep(i,n){
        mp[d[i]]++;
    }
    ll ans = 0;
    for(auto &y:mp){
        if(y.first!=(y.first^x))ans += mp[y.first^x]*y.second;
        else ans+=y.second*(y.second-1);
    }
    cout << ans/2 << endl;
}