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
const ll INF = 1e+8+7;
ll n,m,l;
string s,t;
ll d[200010],dp[500][500];

bool dfs(ll p,ll q){
  if(p == n)return q == 0;
  rep(i,0,m){
    if(dfs(p+1,dp[p][i] ^ q))return true;
  }
  return false;
}

int main(){
  cin >> n >> m;
  rep(i,0,n){
    rep(j,0,m){
      cin >> dp[i][j];
    }
  }
  if(!dfs(0,0))puts("Nothing");
  else puts("Found");
  return 0;
}