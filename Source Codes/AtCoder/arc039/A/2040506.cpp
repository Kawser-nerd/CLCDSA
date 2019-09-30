#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <bitset>
#include <cassert>
#include <exception>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> P;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<string> vs;
typedef vector<P> vp;
#define rep(i,a,n) for(ll i = (a);i < (n);i++)
#define per(i,a,n) for(ll i = (a);i > (n);i--)
#define lep(i,a,n) for(ll i = (a);i <= (n);i++)
#define pel(i,a,n) for(ll i = (a);i >= (n);i--)
#define clr(a,b) memset((a),(b),sizeof(a))
#define pb push_back
#define mp make_pair
#define all(c) (c).begin(),(c).end()
#define sz size()
#define print(X) cout << (X) << endl
const ll INF = 1e+9+7;
ll n,m,l;
string s,t;
ll d[200010],dp[500][500];

int to_int(string str){
  int res = 0;
  rep(i,0,str.sz){
    res += (str[i]-'0') * pow(10,str.sz-i-1);
  }
  return res;
}

int main(){
  cin >> s >> t;
  int ans = -INF;
  rep(i,0,s.sz){
    string p = s;
    int k = 0;
    if(i == 0)k = 1;
    rep(j,k,10){
      p[i] = '0'+j;
      ans = max(ans,to_int(p)-to_int(t));
    }
  }
  rep(i,0,t.sz){
    string p = t;
    int k = 0;
    if(i == 0)k = 1;
    rep(j,k,10){
      p[i] = '0'+j;
      ans = max(ans,to_int(s)-to_int(p));
    }
  }
  print(ans);
  return 0;
}