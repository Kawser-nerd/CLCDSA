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

int main(){
  cin >> s;
  vector<char> vec;
  t = "";
  rep(i,0,s.sz){
    if('0' <= s[i] && s[i] <= '9' && '0' <= s[i+1] && s[i+1] <= '9'){
      t += s[i];
      t += s[i+1];
      break;
    }else if('0' <= s[i] && s[i] <= '9'){
      vec.pb(s[i]);
    }
  }
  if(t != "")print(t);
  else{
    rep(i,0,vec.sz){
      if(vec[i] != '0'){
        print(vec[i]);
        break;
      }
    }
  }
  return 0;
}