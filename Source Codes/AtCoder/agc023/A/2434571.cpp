#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<climits>
#include<iostream>
#include<algorithm>
#include<stack>
#include<queue>
#include<vector>
#include<list>
#include<map>
#include<set>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
#define pb push_back
int dy[]={0, 0, 1, -1, 0};
int dx[]={1, -1, 0, 0, 0};
 
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define RFOR(i,a,b) for (int i=(b)-1;i>=(a);i--)
#define REP(i,n) for (int i=0;i<(n);i++)
#define RREP(i,n) for (int i=(n)-1;i>=0;i--)
ll n,a[300000];
map<ll,ll> m;
int main(){
    cin >> n;
    a[0] = 0;
    REP(i,n) {
        cin >> a[i + 1];
    }
    REP(i,n) {
        a[i + 1] += a[i];
    }

    REP(i,n + 1) {
        if(m.find(a[i]) == m.end()) {
            m[a[i]] = 1;
        }else{
            m[a[i]]++;
        }
    }

    ll ans = 0;
    for(auto v : m) {
        if(v.second > 1) {
            ans += v.second * (v.second - 1) / 2;
        }
    }
    cout << ans << endl;
    return 0;
}