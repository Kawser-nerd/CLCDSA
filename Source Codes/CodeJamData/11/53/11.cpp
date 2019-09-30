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
#include <assert.h>

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

int dr[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dc[] = {-1, 0, 1, -1, 1, -1, 0, 1};

int row,col;

int arah[4][2];

pair<int,int> getadj(pair<int,int> lokasi, int direction) {
  return MP((lokasi.A + dr[direction] + row) % row, (lokasi.B + dc[direction] + col) % col);
}

int visited[105][105];
vector< vint > nneigh;
vector< vector< vector< pair<int,int> > > > neigh;
vector< vint > peta;

void visit(int r, int c) {
  if (visited[r][c]) return;
  visited[r][c] = 1;
  FORN(i, SZ(neigh[r][c])) {
    pair<int,int> nei = neigh[r][c][i];
    FORN(j, 2) {
      int a = arah[peta[nei.A][nei.B]][j];
      visit(getadj(nei, a).A, getadj(nei, a).B);
    }
  }
}

int main() {
  // -
  // |
  // itu
  // /

  // 0 1 2
  // 3   4
  // 5 6 7
  arah[0][0] = 3;
  arah[0][1] = 4;
  arah[1][0] = 1;
  arah[1][1] = 6;
  arah[2][0] = 0;
  arah[2][1] = 7;
  arah[3][0] = 2;
  arah[3][1] = 5;

  int ntc;
  cin >> ntc;
  FORN(itc, ntc) {
    printf("Case #%d: ", itc+1);
    cin >> row >> col;
    peta = vector< vint > (row, vint(col,0));
    FORN(r, row) {
      string buf;
      cin >> buf;
      FORN(c, col) {
        if (buf[c] == '-') peta[r][c] = 0;
        else if (buf[c] == '|') peta[r][c] = 1;
        else if (buf[c] == '\\') peta[r][c] = 2;
        else if (buf[c] == '/') peta[r][c] = 3;
        else {
          assert(false);
        }
      }
    }

    nneigh = vector< vint >(row, vint(col, 0));
    neigh = vector< vector< vector< pair<int,int> > > >(row, vector< vector< pair<int,int> > >(col));

    // bikin neighbors
    int ok = 1;
    FORN(r, row) FORN(c, col) {
      FORN(k, 2) {
        int kode = peta[r][c];
        int a = arah[kode][k];
        int nr = getadj(MP(r, c), a).A;
        int nc = getadj(MP(r, c), a).B;
        nneigh[nr][nc]++;
        neigh[nr][nc].PB(MP(r, c));
      }
    }

    queue< pair<int,int> > proc;
    vector< vint > sudah(row, vint(col, 0));

    FORN(r, row) if (ok) FORN(c, col) {
      if (nneigh[r][c] == 0) {
        ok = 0;
        break;
      }
      if (nneigh[r][c] == 1) {
        proc.push(MP(r, c));
        sudah[r][c] = 1;
      }
    }
    if (!ok) {
      cout << 0 << endl;
      continue;
    }

    while (!proc.empty()) {
      int r = proc.front().A;
      int c = proc.front().B;
      proc.pop();

      // assign direction
      pair<int,int> nei = neigh[r][c][0];
      int k = 0;
      if (getadj(nei, arah[peta[nei.A][nei.B]][1]) == MP(r, c)) k = 1;

      // the other becomes bad
      pair<int,int> other = getadj(nei, arah[peta[nei.A][nei.B]][(k+1)%2]);
      nneigh[other.A][other.B]--;
      neigh[other.A][other.B].erase(find(ALL(neigh[other.A][other.B]), nei));
      if (nneigh[other.A][other.B] == 0) {
        ok = 0;
        break;
      }
      if (nneigh[other.A][other.B] == 1) {
        assert (!sudah[other.A][other.B]);
        sudah[other.A][other.B] = 1;
        proc.push(other);
      }
    }

    if (!ok) {
      cout << 0 << endl;
      continue;
    }

    FORN(r, row) FORN(c, col) assert(sudah[r][c] || nneigh[r][c] == 2);

    ll ret = 1LL;
    ll modu = 1000003LL;

    FORN(r, row) FORN(c, col) visited[r][c] = 0;

    FORN(r, row) FORN(c, col) if (!visited[r][c] && nneigh[r][c] == 2) {
      visit(r, c);
      ret *= 2LL;
      ret %= modu;
    }

    cout << ret << endl;
  }

  return 0;
}
