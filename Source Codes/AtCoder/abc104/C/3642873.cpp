#include <iostream>
#include <vector>
#include <utility>

using namespace std;

typedef long long LL;

#define ARRAY_LENGTH(array) (sizeof(array) / sizeof(array[0]))
#define ALL(a)  (a).begin(),(a).end()
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)

#define dump(x)  cerr << #x << " = " << (x) << endl;


int main() {
  int D, G;
  cin >> D >> G;
  vector<int> p(D), c(D);
  REP(i, D) {
    cin >> p[i] >> c[i];
  }

  int mask = 0, result = 1e9;
  for (mask=0; mask<(1<<D); ++mask) {
    int point = 0, num = 0, rest_max = -1;
    for (int i=0; i<D; ++i) {
      if (mask >> i & 1) {
        point += (i+1)*p[i]*100 + c[i];
        num += p[i];
      } else {
        rest_max = i;
      }
    }
    if (point < G) {
      int d = (rest_max+1)*100;
      int need = (G - point + d - 1) / d;
      if (need >= p[rest_max]) continue;
      num += need;
    }
    result = min(result, num);
  }
  cout << result << endl;
  return 0;
}