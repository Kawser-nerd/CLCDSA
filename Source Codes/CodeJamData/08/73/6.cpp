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
#include <sstream>
using namespace std;

#define X first
#define Y second
#define VV vector
#define PB push_back
#define ll long long
#define ld long double
#define REP(i,n) FOR(i,0,(n)-1)
#define FOR(i,a,b) for(VAR(i,a);i<=(b);++i)
#define FORD(i,a,b) for(VAR(i,a);i>=(b);--i)
#define FORE(a,b) for(VAR(a,(b).begin());a!=(b).end();++a)
#define VAR(a,b) __typeof(b) a=(b)
#define SS(a) ((int)((a).size()))
#define ALL(x) (x).begin(),(x).end()
#define CLR(x,a) memset(x,a,sizeof(x))
#define VI VV<int>
#define VS VV<string>
#define MP make_pair
int COND = 1;
#define DB(x) { if (COND > 0) { COND--; REP (xxx, 1) cerr << __LINE__<< " " << #x << " " << x << endl; cerr.flush(); } }
int QQQ, M;
ld A[40][4];
set <ll> VIS;
#define sss(x, p, v) (((x) & ~(3LL<<(2*p))) | ((ll) (v) << (2*p)))
#define val(x, p) (((x) >> (2*p)) & 3)
ld prob(ll st) {
  ld ret = 1;
  DB(st);
  REP (i, M) {
    DB(val(st, i)<<" "<<A[i][val(st, i)]);
    ret *= A[i][val(st, i)]; 
  }
  return ret;
}

int main(int argc, char **argv) {
	COND = argc >= 2 && argv[1][0] == 'q' ? (int)1e9 : 0;
  int C;
  cin >> C;
  FOR (mycase, 1, C) {
    cerr << mycase << endl;
    VIS.clear();
    cin >> QQQ >> M;
    REP (i, M) REP (j, 4) cin >> A[i][j];
    ll st = 0;
    REP (i, M) {
      sort(A[i], A[i] + 4);
      reverse(A[i], A[i] + 4);
    }
    DB(st);
    multimap <ld, ll, greater<ld> > KO; VIS.insert(st);  KO.insert(MP(prob(st), st));
    ld ret = 0;
    while (KO.size() && QQQ) {
      QQQ--;
      ld pr = KO.begin()->X;
      ll cur = KO.begin()->Y;
      DB(cur<<" "<<pr);
      ret += pr;
      KO.erase(KO.begin());

      REP (i, M) {
        ll qu = val(cur, i);
        if (qu + 1 <= 3) {
          ll ne = sss(cur, i, (qu + 1));
          if (VIS.count(ne) == 0) {
            VIS.insert(ne);
            KO.insert(MP(prob(ne), ne));
          }
        }
      }
    }
    DB(QQQ<<" "<<KO.size()<<" "<<M);
    printf("Case #%d: %.9lf\n", mycase, (double)ret);
  }

	return 0;
}
