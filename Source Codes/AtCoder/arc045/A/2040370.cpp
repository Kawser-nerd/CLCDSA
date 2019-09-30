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

vs split(string str,char del){
  vs res;
  string cut = "";
  rep(i,0,str.sz){
    if(s[i] == del){
      res.pb(cut);
      cut = "";
      i++;
    }
    cut += s[i];
  }
  if(cut.sz != 0)res.pb(cut);
  return res;
}

int main(){
  getline(cin,s);
  vs vec = split(s,' ');
  rep(i,0,vec.sz){
    if(vec[i] == "Left")cout << "<";
    else if(vec[i] == "Right")cout << ">";
    else if(vec[i] == "AtCoder")cout << "A";
    if(i == vec.sz-1)break;
    cout << " ";
  }
  puts("");
  return 0;
}