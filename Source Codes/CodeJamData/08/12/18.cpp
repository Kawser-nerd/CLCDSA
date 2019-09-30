#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <numeric>
#include <cmath>
#include <cstdlib>
#include <iostream>
using namespace std;

#define X first
#define Y second
#define MP make_pair
#define PB push_back
typedef long long ll;
typedef double D;
typedef long double ld;
typedef vector<int> VI;
typedef pair<int,int> PII;
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(VAR(i,a);i<=(b);++i)
#define FORD(i,a,b) for(VAR(i,a);i>=(b);--i)
#define FORE(a,b) for(VAR(a,(b).begin());a!=(b).end();++a)
#define VAR(a,b) __typeof(b) a=(b)
#define SIZE(a) ((int)((a).size()))
#define ALL(x) (x).begin(),(x).end()
#define CLR(x,a) memset(x,a,sizeof(x))
int COND = 0;
#define DB(x) { if (COND) { cerr << __LINE__ << " " << #x << " " << x << endl; } }

#define SZ 2111
#define VV vector

int n, m;
int VAL[SZ];
int ONE[SZ];
int ILE[SZ];
VV <int> REQ[SZ];

int main(int argc, char **argv) {
  COND = argc >= 2 && argv[1][0] == 'q';
  ios::sync_with_stdio(false);

  int t; cin >> t;
  FOR (mycase, 1, t) {
    cin >> n >> m;
    CLR(VAL, 0);
    CLR(ONE, -1);
    CLR(ILE, 0);
    DB(n<<" "<<m);
    REP (i, SZ) REQ[i].clear();

    REP (i, m) {
      int K; cin >> K;
      REP (j, K) {

	int x, y; cin >> x >> y; x--;
	if (y) {
	  ONE[i] = x;
	}
	else {
	  ILE[i]++; REQ[x].PB(i);
	}
      }
    }

    bool solve = true;
    while   (true) {
      bool ok = false;
      REP (i, m) {
	if (ILE[i] == 0) {
	  DB(i);
	  ILE[i]--;
	  if (ONE[i] == -1) {
	    solve = false;
	  }
	  else {
	    int cand = ONE[i];
	    if (VAL[cand] == 0) {
	      VAL[cand] = 1;
	      FORE (it, REQ[cand]) ILE[*it]--;
	      REQ[cand].clear();
	     
	      ok = true;
	    }
	  }
	}
      }

      if (solve == false || ok == false) break;
    }
    if (solve == false)
      printf("Case #%d: IMPOSSIBLE\n", mycase);
    else {
      printf("Case #%d:", mycase);
      REP (i, n) printf(" %d", VAL[i]);

      printf("\n");
    }
  }
    
  return 0;
}
