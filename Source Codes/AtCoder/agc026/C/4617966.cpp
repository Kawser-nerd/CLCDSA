#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <tuple>
#include <cassert>

using namespace std;

#define all(c) (c).begin(), (c).end()
#define iter(c) __typeof((c).begin())
#define cpresent(c, e) (find(all(c), (e)) != (c).end())
#define tr(c, i) for (iter(c) i = (c).begin(); i != (c).end(); ++i)
#define pb(e) push_back(e)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n)   FOR(i,0,n)
#define mp(a,b) make_pair((a), (b))
#define mt(a,b,c) make_tuple((a),(b),(c))

typedef long long ll;
int tb[32];

bool isup(int x,int i){
    return (x&(1<<i)) == (1<<i);
}

int popcnt(int x){
    int ans = 0;
    rep(i,18) ans += ( (x&(1<<i)) == (1<<i) ? 1 : 0);
    return ans;
}

int main(){
    int n; string s; cin >> n >> s;
    rep(i,32) tb[i] = 0;
    rep(i,2*n) tb[s[i] - 'a']++;
    rep(i,32){
        if(tb[i] % 2 != 0){cout << 0 << endl; return 0;}
        tb[i] /= 2;
    }
    map<pair<int, string>, int> m;
    rep(i, 1<<n){
        string rs,bs;
        rep(j,n){
            if(isup(i,j)) rs += s[j];
            else bs += s[j];
        }
        reverse(all(bs));
        pair<int,string> tem = make_pair(popcnt(i), rs + bs);
      //  cout << popcnt(i) << ":" << rs + bs << endl;
        if(m.find(tem) == m.end()) m[tem] = 1;
        else m[tem]++;
    }
    reverse(all(s));
  //  cout << "*****" << endl;
    ll ans = 0;
    rep(i, 1<<n){
        string rs,bs;
        rep(j,n){
            if(isup(i,j)) rs += s[j];
            else bs += s[j];
        }
        reverse(all(rs));
        pair<int,string> tem = make_pair(bs.length(), bs + rs);
      // cout << rs.length() << ":" << bs + rs << ":" << m[tem] << endl;
        if(m.find(tem) != m.end()) ans = ans + m[tem];
    }
    cout << ans << endl;
    return 0;
}