// Authored by dolphinigle
// GCJ 2013 1B
// 4 May 2013

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
#include <fstream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <assert.h>

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

#define FORIT(X,Y) for(typeof((Y).begin()) X = (Y).begin();X!=(Y).end();X++)

using namespace std;

typedef long long ll;
typedef double db;
typedef vector<int> vint;

int dp[10000][10];

int main() {
  ifstream myReadFile;
//  myReadFile.open("bdict.txt");
  myReadFile.open("garbled_email_dictionary.txt");
  int longest = 0;
  vector<string> words;
  if (myReadFile.is_open()) {
    string x;
    while ((myReadFile >> x)) {
      MX(longest, SZ(x));
      words.PB(x);
    }
  }
  myReadFile.close();
  map<string, vint*> mvi[8];

  FORN(j, SZ(words)) {
    string z = words[j].substr(0, 5);
    FORN(i, SZ(z)) {
      string y = z;
      y[i] = '?';
      if (!mvi[SZ(y)].count(y)) {
        mvi[SZ(y)][y] = new vint();
      }
      mvi[SZ(y)][y]->PB(j);
    }
  }
  int maxim = 0;
  FORN(i, 6) FORIT(it, mvi[i]) if (int(it->B->size()) >= maxim) {
    maxim = int(it->B->size());
  }

  int ntc;
  cin >> ntc;
  FORN(itc, ntc) {
    cout << "Case #" << (itc+1) << ": ";
    string x;
    cin >> x;
    FORN(i, 10000) FORN(j, 10) dp[i][j] = INF;
    dp[0][5] = 0;
    FORN(i, SZ(x)) {
      // calculate members
      string mpos = "";
      FORN(j, 5) {
        if (i+j >= SZ(x)) continue;
        mpos += x[i+j];
      }
      vint members;
      REP(j, 1, 6) {
        // this length
        string kuman = mpos.substr(0, j);
        FORN(k, j) {
          string deskuman = kuman;
          deskuman[k] = '?';
          if (mvi[j].count(deskuman)) {
            vint* itu = mvi[j][deskuman];
            FORIT(it, (*itu)) {
              members.PB(*it);
            }
          }
        }
      }
      sort(ALL(members));
      members.erase(unique(ALL(members)), members.end());

      FORIT(it, members) {
        if (i + SZ(words[*it]) > SZ(x)) continue;
        int first_error = INF;
        int last_error = -INF;
        int ok = 1;
        int errors = 0;
        FORN(j, SZ(words[*it])) {
          if (words[*it][j] == x[i+j]) continue;
          if (j - last_error < 5) {
            ok = 0;
            break;
          }
          last_error = j;
          if (first_error == INF) first_error = j;
          errors += 1;
        }
        if (!ok) continue;
        FORN(j, 6) if (dp[i][j] != INF) {
          if (first_error - (-j) < 5) continue;
          // good
          int nex = j;
          if (errors == 0) {
            nex = j + SZ(words[*it]);
          } else {
            nex = SZ(words[*it]) - last_error;
          }
          MN(nex, 5);
          MN(dp[i+SZ(words[*it])][nex], dp[i][j] + errors);
        }
      }
    }
    int res = INF;
    FORN(i, 6) MN(res, dp[SZ(x)][i]);
    cout << res << endl;
  }
  return 0;
}
