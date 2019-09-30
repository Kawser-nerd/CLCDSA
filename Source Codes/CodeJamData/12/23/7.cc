// Authored by dolphinigle
// GCJ 2012 1B
// 5 May 2012

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
#include <assert.h>

#define FORN(X,Y) for (int (X) = 0;(X) < (Y);++(X))
#define REP(X,Y,Z) for (int (X) = (Y);(X) < (Z);++(X))

#define SZ(Z) ((int)(Z).size())
#define ALL(W) W.begin(), W.end()
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

ll v[505];
vint pop[1000005];
ll jml[505];
pair<ll, vint> cand[1000005];
int npop;

void Print(vint numbers) {
  vector<ll> kir;
  vector<ll> kan;
  FORN(i, SZ(numbers)) {
    assert(numbers[i] == -1 || numbers[i] == 1 || numbers[i] == 0);
    if (numbers[i] < 0) kan.PB(v[i]);
    if (numbers[i] > 0) kir.PB(v[i]);
  }
  
  FORN(i, SZ(kir)) {
    if (i) cout << " ";
    cout << kir[i];
  }
  cout << endl;
  FORN(i, SZ(kan)) {
    if (i) cout << " ";
    cout << kan[i];
  }
  cout << endl;
  
  ll sum1 = 0LL;
  ll sum2 = 0LL;
  FORIT(it, kir) sum1 += *it;
  FORIT(it, kan) sum2 += *it;
  assert (sum1 == sum2);
  assert(kir != kan);
}

int main() {
  srand(29384);
  int ntc;
  cin >> ntc;
  
  FORN(itc, ntc) {
    cout << "Case #" << (itc+1) << ":\n";
    int n;
    cin >> n;
    
    FORN(i, n) {
      cin >> v[i];
    }
    
    int ok = 1;
    while (ok) {
      // Genetic Algorithm
      
      FORN(i, n) {
        vint baw(n);
        baw[i] = 1;
        pop[i] = baw;
      }
      npop = n;
      
      random_shuffle(pop, pop + npop);
      int iter = 0;
      while (iter < 250) {
        // cout << iter << endl;
        ++iter;
        // check population, see if any is OKAY
        int nc = 0;
        FORN(i, npop) {
          ll sum = 0LL;
          FORN(j, 500) sum += (ll)pop[i][j] * v[j];
          if (sum == 0LL) {
            if (pop[i] != vint(n)) {
              Print(pop[i]);
              ok = 0;
              break;
            }
          } else {
            cand[nc] = MP(sum, pop[i]);
            ++nc;
          }
        }
        if (!ok) break;
        // calculate limit
        int limit = 200;
        
        // selection
        sort(cand, cand + nc);
        nc = unique(cand, cand + nc) - cand;
        FORN(i, min(limit, nc)) {
          pop[i] = cand[i].B;
          jml[i] = cand[i].A;
        }
        npop = min(limit, nc);
        // cross breed
        int tnpop = npop;
        FORN(i, npop) {
          REP(j, i+1, npop) {
            vint newp(500);
            int add1 = 1;
            int add2 = -1;
            FORN(k, 500) newp[k] = add1 * pop[i][k] + add2 * pop[j][k];
            FORN(k, 500) {
              if (newp[k] < -1) newp[k] = -1;
              if (newp[k] > 1) newp[k] = 1;
            }
            ll sum = 0LL;
            FORN(k, 500) sum += (ll)newp[k] * v[k];
            if (sum < 0LL) {
              // reverse
              FORN(k, 500) newp[k] *= -1;
            }
            pop[tnpop] = newp;
            ++tnpop;
          }
        }
        // discard the initial ones
        FORN(i, npop) {
          pop[i] = pop[tnpop - i - 1];
          --tnpop;
        }
        npop = tnpop;
      }
    }
    
  }
  
}
