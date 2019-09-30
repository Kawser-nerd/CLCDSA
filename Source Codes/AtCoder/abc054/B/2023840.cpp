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
typedef pair<string,ll> P;
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
ll d[100000],dp[100][100];
char a[100][100],b[100][100];

int main(){
  cin >> n >> m;
  rep(i,0,n){
    rep(j,0,n){
      cin >> a[i][j];
    }
  }
  rep(i,0,m){
    rep(j,0,m){
      cin >> b[i][j];
    }
  }
  s = "No";
  rep(i,0,n){
    rep(j,0,n){
      l = 0;
      rep(k,0,m){
        rep(p,0,m){
          if(a[i+k][j+p] == b[k][p])l++;
        }
      }
      if(l == m*m)s = "Yes";
    }
  }
  print(s);
  return 0;
}