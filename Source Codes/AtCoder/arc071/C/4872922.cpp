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

int ceil(int x, int y){
  return (x % y == 0) ? x / y : x / y + 1;
}

int gcd(int x, int y){
  return y ? gcd(y, x % y) : x;
}

int lcm(int x, int y){
  return x / gcd(x, y) * y;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  string s, t;
  cin >> s >> t;
  int q;
  cin >> q;
  int a[q], b[q], c[q], d[q];
  for(int i = 0; i < q; i++){
    cin >> a[i] >> b[i] >> c[i] >> d[i];
    --a[i]; --c[i];
  }

  int as[s.length() + 1];
  as[0] = 0;
  for(int i = 1; i <= s.length(); i++){
    as[i] = as[i - 1] + (s[i - 1] == 'A' ? 1 : 0);
  }

  int at[t.length() + 1];
  at[0] = 0;
  for(int i = 1; i <= t.length(); i++){
    at[i] = at[i - 1] + (t[i - 1] == 'A' ? 1 : 0);
  }

  string buf;
  for(int i = 0; i < q; i++){
    int tmps = as[b[i]] - as[a[i]] + 
      2 * ((b[i] - a[i]) - (as[b[i]] - as[a[i]]));
    int tmpt = at[d[i]] - at[c[i]] + 
      2 * ((d[i] - c[i]) - (at[d[i]] - at[c[i]]));
    if((tmps % 3) == (tmpt % 3)) buf += "YES\n";
    else buf += "NO\n";
  }

  cout << buf;

  return 0;
}