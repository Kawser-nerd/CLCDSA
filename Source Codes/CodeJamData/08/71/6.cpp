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

#define VV vector
#define PB push_back
#define ll long long
#define ld long double
#define REP(i,n) FOR(i,0,(int)(n)-1)
#define FOR(i,a,b) for(VAR(i,a);i<=(b);++i)
#define FORD(i,a,b) for(VAR(i,a);i>=(b);--i)
#define FORE(a,b) for(VAR(a,(b).begin());a!=(b).end();++a)
#define VAR(a,b) __typeof(b) a=(b)
#define SS(a) ((int)((a).size()))
#define ALL(x) (x).begin(),(x).end()
#define CLR(x,a) memset(x,a,sizeof(x))
#define VI VV<int>
#define VS VV<string>
int COND = 1;
#define DB(x) { if (COND > 0) { COND--; REP (xxx, 1) cerr << __LINE__<< " " << #x << " " << x << endl; cerr.flush(); } }
map <string, int> S2I; 
int N, M;
#define  SZ 1111
VV<int> ED[SZ];
int PR[SZ];
int REQ[SZ];

int GETID(string tmp) {
  if (islower(tmp[0])) return -1;
  if (S2I.count(tmp)) return S2I[tmp];
  int val = S2I.size();
  return S2I[tmp] = val;
}

int solve(int i) {
  DB(i<<" "<<REQ[i]);
  if (REQ[i] != -1) return REQ[i];
  int &cnt = REQ[i] = 1;
  VV <int> LST;
  FORE (it, ED[i])  LST.PB(solve(*it));

  FORE (it, ED[i]) DB(i<<" "<<*it);
    
  sort(ALL(LST));
  reverse(ALL(LST));
  cnt = max(cnt, (int)LST.size() + 1);
  FORE (it, LST)
    cnt = max(cnt, *it + (it - LST.begin()));

  return cnt;
}

int main(int argc, char **argv) {
	COND = argc >= 2 && argv[1][0] == 'q' ? (int)1e9 : 0;
  int C;
  cin >> C;
  FOR (mycase, 1, C) {
    S2I.clear();
    REP (i, SZ) ED[i].clear();
    CLR(PR, 0); CLR(REQ, -1);
    cin >> N;
    DB(N);
    REP (i, N) { string tmp, arg;
      cin >> tmp >> M;
      int le = GETID(tmp);
      DB(le);
      REP (j, M) { cin >> arg;
        int ri = GETID(arg);
        if (ri != -1) {
          ED[le].PB(ri);
          PR[ri]++;
        }
      }
    }
    int ret = -1;
    REP (i, N)  if (PR[i] == 0) { DB(i);  ret = solve(i); }
    cout << "Case #"<<mycase << ": " << ret << endl;
  }

	return 0;
}
