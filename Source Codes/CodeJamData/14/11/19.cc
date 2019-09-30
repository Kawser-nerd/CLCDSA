// Authored by dolphinigle

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
#include <cstring>
#include <cassert>

#define FORN(X,Y) for (int (X) = 0;(X) < (Y);++(X))
#define REP(X,Y,Z) for (int (X) = (Y);(X) < (Z);++(X))

#define SZ(Z) ((int)(Z).size())
#define ALL(W) (W).begin(), (W).end()
#define PB push_back

#define MP make_pair
#define A first
#define B second

#define INF 1023123123
#define EPS 1e-11

#define MX(Z,Y) Z = max((Z),(Y))
#define MN(X,Y) X = min((X),(Y))

#define FORIT(X,Y) for(__typeof__((Y).begin()) X = (Y).begin();X!=(Y).end();X++)

using namespace std;

typedef long long ll;
typedef double db;
typedef vector<int> vint;

int outlet[160][50];
int device[160][50];
int changed[50];

int main() {
  int ntc;
  cin >> ntc;
  FORN(itc, ntc) {
    printf("Case #%d: ", itc+1);
    int n, l;
    cin >> n >> l;
    FORN(i, n) {
      string str;
      cin >> str;
      FORN(j, l) outlet[i][j] = (str[j] - '0');
    }
    FORN(i, n) {
      string str;
      cin >> str;
      FORN(j, l) device[i][j] = (str[j] - '0');
    }

    int best = INF;
    FORN(i, n) {
      int changes = 0;
      FORN(j, l) {
        if (device[0][j] != outlet[i][j]) {
          changes += 1;
          changed[j] = 1;
        } else {
          changed[j] = 0;
        }
      }
      set<string> sd;
      set<string> so;
      FORN(j, n) {
        string x = "";
        FORN(k, l) x += (char)('0' + device[j][k]);
        sd.insert(x);
      }
      FORN(j, n) {
        string x = "";
        FORN(k, l) x += (char)('0' + (outlet[j][k] ^ changed[k]));
        so.insert(x);
      }
      if (sd == so) {
        MN(best, changes);
      }
    }
    if (best == INF) {
      printf("NOT POSSIBLE\n");
    } else {
      cout << best << endl;
    }
  }
  return 0;
}



