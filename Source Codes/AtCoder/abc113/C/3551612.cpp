#include <iostream>
#include <climits>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <deque>
#define INF_INT (INT_MAX / 2)
#define INF_LONG (LONG_MAX / 2)
//#define DEBUG true
#define DEBUG false
using namespace std;

const int MAX = 100001;
const int MOD = 1000000007;

typedef long long ll;
typedef pair< int, int > pii;
typedef pair< ll, ll > pll;
typedef pair< ll, int > pli;
typedef pair< int, ll > pil;

ll pow(ll a, int b){
  ll r = 1;
  for(int i = 0; i < b; i++){
    r *= a;
  }
  return r;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, m;
  cin >> n >> m;
  int p[m], y[m];
  for(int i = 0; i < m; i++) cin >> p[i] >> y[i];

  vector< set< pii > > v(n);
  for(int i = 0; i < m; i++){
    v[p[i] - 1].insert(make_pair(y[i], i));
  }

  ll id[m];
  for(int i = 0; i < n; i++){
    int x = 0;
    for(pii pi: v[i]){
      int j = pi.second;
      id[j] = p[j] * pow(10, 6) + (x + 1);
      ++x;
    }
  }

  char buf[20 * m];
  for(int i = 0; i < m; i++){
    sprintf(buf + (13 * i), "%012lld\n", id[i]);
  }

  cout << buf;

  return 0;
}