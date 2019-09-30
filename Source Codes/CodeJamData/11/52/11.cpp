//Authored by dolphinigle
//GCJ R3 2011
//Jun 11 2011

#include <vector>
#include <list>
#include <map>
#include <set>

#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

#define FORN(X,Y) for (int (X) = 0;(X) < (Y);++(X))
#define DEBUG(x) cout << '>' << #x << ':' << x << '\n';

#define REP(X,Y,Z) for (int (X) = (Y);(X) < (Z);++(X))
#define RESET(Z,Y) memset(Z,Y,sizeof(Z))

#define SZ(Z) ((int)Z.size())
#define ALL(W) W.begin(), W.end()
#define PB push_back

#define MP make_pair
#define A first
#define B second

#define INF 1023123123
#define EPS 1e-8

#define MX(Z,Y) Z = max((Z),(Y))
#define MN(X,Y) X = min((X),(Y))

#define FORIT(X,Y) for(typeof((Y).begin()) X = (Y).begin();X!=(Y).end();X++)

using namespace std;

typedef long long ll;
typedef double db;
typedef vector<int> vint;
typedef vector<ll> vll;

int main() {

  int ntc;
  cin >> ntc;
  FORN(itc, ntc) {
    printf("Case #%d: ", itc+1);
    int n;
    cin >> n;

    if (n == 0) {
      cout << 0 << endl;
      continue;
    }

    vint occ(10004, 0);
    FORN(i, n) {
      int buf;
      scanf("%d", &buf);
      occ[buf]++;
    }

    int ret = INF;
    deque<int> numset;
    FORN(i, 10002) {
      FORN(j, occ[i]) {
        if (j < SZ(numset)) {
          // merge
          numset[j]++;
        } else {
          // add new
          numset.push_front(1);
        }
      }
      while (SZ(numset) > occ[i]) {
        MN(ret, numset.back());
        numset.pop_back();
      }
    }
    cout << ret << endl;
  }

  return 0;
}
