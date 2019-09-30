#include <queue>
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

const int MAX = 35, MAXN = 10;
const int INF = 0x3f3f3f3f;

char s[MAX][MAX];
int id[MAX][MAX];
P poz_tur[MAXN], poz_sol[MAXN];
int brred, brstup;
int br_tur, br_sol;
int can[1<<MAXN][MAXN][MAXN]; //mask_tur, ind_cov, ind_tur
int pr[4] = {1, 0, -1, 0}, ps[4] = {0, 1, 0, -1};
int moves;

int vani(int red, int stup) {
  return red < 0 || red >= brred || stup < 0 || stup >= brstup;
}

void bfs(P poc, int udalj[MAX][MAX], int nein[MAX][MAX]) {
  queue <P> Q;
  Q.push(poc);
  udalj[poc.X][poc.Y] = 0;
  
  for (; !Q.empty(); ) {
    P tmp = Q.front(); Q.pop();
    //    TRACE(tmp.X _ tmp.Y _ nein[tmp.X][tmp.Y]);
    if (nein[tmp.X][tmp.Y]) continue;
    //    TRACE(tmp.X _ tmp.Y);
    int nval = udalj[tmp.X][tmp.Y] + 1;

    REP(dir, 4) {
      int nr = tmp.X + pr[dir];
      int ns = tmp.Y + ps[dir];
      if (!vani(nr, ns) && udalj[nr][ns] > nval) {
	udalj[nr][ns] = nval;
	Q.push(P(nr, ns));
      }
    }
  }
}

void gen_dist(int msk) {
  int nein[MAX][MAX];
  memset(nein, 0, sizeof nein);
  int see[MAX][MAX][MAX];
  memset(see, 0, sizeof see);

  REP(i, brred) {
    REP(j, brstup) {
      if (s[i][j] == '#') nein[i][j] = 1;
    }
  }
  
  REP(i, br_tur) {
    if (msk>>i & 1) continue;

    REP(dir, 4) {
      int red = poz_tur[i].X;
      int stup = poz_tur[i].Y;

      for (;;) {
	if (vani(red, stup) || s[red][stup] == '#') break;
	see[red][stup][i] = 1;
	nein[red][stup] = 1;
	red += pr[dir];
	stup += ps[dir];
      }
    }
  }

  // if (msk == 4) {
  //   REP(i, brred) {
  //     REP(j, brstup)
  // 	printf("%d", nein[i][j]);
  //   printf("\n");
  //   }    
  //   printf("AAH\n");
  // }

  //  TRACE(msk);
  REP(i, br_sol) {
    int udalj[MAX][MAX];
    memset(udalj, INF, sizeof udalj);
    bfs(poz_sol[i], udalj, nein);

    //    if (msk == 4 && !i) TRACE(udalj[0][0]);

    REP(j, br_tur) {
      can[msk][i][j] = 0;
      
      REP(red, brred) {
	REP(stup, brstup) {
	  //	  TRACE(red _ stup _ udalj[red][stup] _ nein[red][stup]);
	  if (udalj[red][stup] <= moves && see[red][stup][j]) {
	    //	    if (msk == 4 && !i && !j) TRACE(red _ stup);
	    //	    if (msk == 6) TRACE("can" _ msk _ i _ j);
	    can[msk][i][j] = 1;
	  }
	}
      }
    }
  }
}

void gen() {
  br_tur = br_sol = 0;

  REP(i, brred) {
    REP(j, brstup) {
      if (s[i][j] == 'S') {
	id[i][j] = br_sol;
	poz_sol[br_sol++] = P(i, j);
      }
      if (s[i][j] == 'T') {
	id[i][j] = br_tur;
	poz_tur[br_tur++] = P(i, j);
      }
    }
  }

  //  TRACE(br_tur _ br_sol);

  REP(i, 1<<br_tur)
    gen_dist(i);
}

int dp[1<<MAXN][1<<MAXN];

int rek(int msk_sol, int msk_tur, int rec) {
  if (!rec && dp[msk_sol][msk_tur] != -1)
    return dp[msk_sol][msk_tur];

  //  TRACE(can[4][0][0]);

  int ret = 0;
  REP(i, br_sol) {
    REP(j, br_tur) {
      if (!((msk_sol >> i) & 1) && !((msk_tur >> j) & 1) &&
	  can[msk_tur][i][j]) {
	
	int tmp = 1 + rek(msk_sol | (1<<i), msk_tur | (1<<j), 0);

	if (rec && tmp == dp[msk_sol][msk_tur]) {
	  printf("%d %d\n", i+1, j+1);
	  rek(msk_sol | (1<<i), msk_tur | (1<<j), 1);
	  return dp[msk_sol][msk_tur];
	}
	else
	  ret = max(ret, tmp);
      }
    }
  }

  return dp[msk_sol][msk_tur] = ret;
}

int main()
{
  int brt;
  scanf("%d", &brt);
  
  FOR(tt, 1, brt+1) {
    scanf("%d%d%d", &brstup, &brred, &moves);
    REP(i, brred) scanf(" %s", s[i]);
    gen();
    memset(dp, -1, sizeof dp);  

    printf("Case #%d: %d\n", tt, rek(0, 0, 0));
    rek(0, 0, 1);
    TRACE(tt);
    //    break;
  }

  return 0;
}
