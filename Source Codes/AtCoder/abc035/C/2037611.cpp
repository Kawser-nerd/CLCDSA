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

int main(){
  int a,b;
  cin >> n >> m;
  clr(d,0);
  rep(i,0,m){
    cin >> a >> b;
    d[a-1]++; d[b]--;
  }
  rep(i,0,n){
    if(d[i] % 2 == 0)cout << 0;
    else cout << 1;
    d[i+1] += d[i];
  }
  puts("");
  return 0;
}