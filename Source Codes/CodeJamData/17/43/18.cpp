#include <stack>
#include <cstdio>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define TRACE(x) cerr << #x << " = " << x << endl
#define REP(i, n) for (int i=0; i<n; i++)
#define FOR(i, a, b) for (int i=(a); i<(b); i++)
#define _ << " " <<

typedef long long ll;
typedef pair<int, int> P;
#define X first
#define Y second

const int MAX = 55;

vector <P> V[MAX][MAX];
char s[MAX][MAX];
int brred, brstup;
int nesmije[MAX][MAX][2];
int pr[4] = {-1, 0, 1, 0};
int ps[4] = {0, 1, 0, -1};

int id(int red, int stup) {
  return red * brstup + stup;
}

int vani(int red, int stup) {
  return red < 0 || red >= brred || stup < 0 || stup >= brstup;
}

int go(int red, int stup, int dir, P stavljam) {
  if (vani(red, stup)) return 1;
  V[red][stup].push_back(stavljam);

  if (s[red][stup] == '-' || s[red][stup] == '|') return 0;
  if (s[red][stup] == '#') return 1;
  if (s[red][stup] == '/') dir ^= 1;
  if (s[red][stup] == '\\') dir ^= 3;
  return go(red + pr[dir], stup + ps[dir], dir, stavljam);
}

int moze(int red, int stup, int dir) {
  return go(red+pr[dir], stup+ps[dir], dir, P(id(red, stup), dir%2));
}

void gen() {
  REP(i, MAX) REP(j, MAX) V[i][j].clear();
  memset(nesmije, 0, sizeof nesmije);
  
  REP(i, brred) {
    REP(j, brstup) {
      if (s[i][j] == '-' || s[i][j] == '|') {
	int tmp = moze(i, j, 0) && moze(i, j, 2);
	if (!tmp) nesmije[i][j][0] = 1;
	
	tmp = moze(i, j, 1) && moze(i, j, 3);
	if (!tmp) nesmije[i][j][1] = 1;
      }
    }
  }
}

namespace tarjan2sat {
  const int MAXN = 100000;

  vector<int> E[MAXN];

  bool ans[MAXN];
  bool stk[MAXN];
  int val[MAXN];
  int disc[MAXN];
  int n, t;
  bool consistent;

  stack<int> S;
  
  int tarjan(int x) {
    int lw = disc[x] = ++t;
    
    stk[x] = true;
    S.push(x);

    for (int y: E[x])
      if (disc[y] == 0) lw = min(lw, tarjan(y)); else
        if (stk[y]) lw = min(lw, disc[y]);
    
    if (lw == disc[x]) {
      vector<int> comp;
      bool ok = true;
      while (!S.empty()) {
        int y = S.top(); S.pop();
        comp.push_back(y);
        ok &= val[y/2] == -1;
        stk[y] = false;
        if (y == x) break;
      }

      if (ok) {
        for (int y: comp)
          val[y/2] = y&1;
        for (int y: comp)
          if (val[y/2] != (y&1)) consistent = false;
      }
    }
    return lw;
  }

  bool solve() {
    consistent = true;
    REP(i, 2*n)
      if (!disc[i]) tarjan(i);
    return consistent;
  }
  
  void add_impl(int i, bool vi, int j, bool vj) {
    E[2*i + vi].push_back(2*j + vj);
    E[2*j + !vj].push_back(2*i + !vi);
  }

  void add_must(int i, bool vi) {
    add_impl(i, !vi, i, vi);
  }
  
  void init(int _n) {
    assert(2*_n < MAXN);
    n = _n, t = 0;
    REP(i, 2*n) {
      disc[i] = 0;
      stk[i] = false;
      E[i].clear();
    }
    REP(i, n) val[i] = -1;
  }
};

void solve(int cid) {
  int ok = 1;
  gen();

  tarjan2sat::init(40000);

  REP(i, brred) {
    REP(j, brstup) {
      if (s[i][j] == '.') {
	vector <P> T;
	for (auto it : V[i][j]) {
	  int red = it.X / brstup;
	  int stup = it.X % brstup;
	  if (!nesmije[red][stup][it.Y]) T.push_back(it);
	}

	assert(T.size() < 3);
	if (T.empty()) { ok = 0; break; }
	if (T.size() == 1)
	  tarjan2sat::add_must(T[0].X, T[0].Y);
	
	if (T.size() == 2) {
	  tarjan2sat::add_impl(T[0].X, !T[0].Y, T[1].X, T[1].Y);
	  tarjan2sat::add_impl(T[1].X, !T[1].Y, T[0].X, T[0].Y);
	}
      }

      if (s[i][j] == '-' || s[i][j] == '|') {
	int ind = id(i, j);
	REP(k, 2)
	  if (nesmije[i][j][k])
	    tarjan2sat::add_must(ind, !k);
      }
    }

    if (!ok) break;
  }

  printf("Case #%d: ", cid);
  if (ok && tarjan2sat::solve()) {
    printf("POSSIBLE\n");
    REP(i, brred) {
      REP(j, brstup) {
	if (s[i][j] == '-' || s[i][j] == '|') {
	  int ind = id(i, j);
	  printf("%c", tarjan2sat::val[ind] ? '-' : '|');
	}
	else printf("%c", s[i][j]);
      }
      printf("\n");
    }
  }
  else
    printf("IMPOSSIBLE\n");
}

int main()
{
  int brt;
  scanf("%d", &brt);

  FOR(tt, 1, brt+1) {
    scanf("%d%d", &brred, &brstup);
    REP(i, brred) scanf(" %s", s[i]);

    solve(tt);
    TRACE(tt);
  }  

  return 0;
}
