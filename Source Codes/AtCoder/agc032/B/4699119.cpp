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

  int n;
  cin >> n;

  int n2 = 2 * (n / 2);

  set< pii > edges;
  for(int v = 1; v <= n; v++){
    for(int w = v + 1; w <= n; w++){
      if(w != (n2 + 1) - v) edges.insert(make_pair(v, w));
    }
  }

  string buf;
  buf += to_string(edges.size()) + "\n";
  for(pii e: edges){
    buf += to_string(e.first) + " " + to_string(e.second) + "\n";
  }

  cout << buf;

  return 0;
}