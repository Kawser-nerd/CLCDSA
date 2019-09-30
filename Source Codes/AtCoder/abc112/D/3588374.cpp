#include <iostream>

using namespace std;

typedef long long LL;

#define ARRAY_LENGTH(array) (sizeof(array) / sizeof(array[0]))
#define ALL(a)  (a).begin(),(a).end()
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)

#define dump(x)  cerr << #x << " = " << (x) << endl;

int gcd(int u, int v) {
  int r;
  while (v != 0) {
    r = u % v;
    u = v;
    v = r;
  }
  return u;
}

int main() {
  int N, M;
  cin >> N >> M;

  int r = M / N, res = -1;
  while(true) {
    if (M % r == 0) {
      res = r;
      break;
    }
    r--;
  }

  cout << res << endl;

  return 0;
}