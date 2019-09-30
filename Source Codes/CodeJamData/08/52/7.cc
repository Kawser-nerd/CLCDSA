/* GCJ'08
 * Author: Per Austrin
 */
#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <deque>
//#include <string>
#include <map>
//#include <vector>

using namespace std;
#define dprintf debug && printf
bool debug = false;

void init() {
}

const int dr[] = {-1, 0, 1, 0};
const int dc[] = {0, -1, 0, 1};

int R, C, RC;
char maze[100][100];
int nextwall[100][100][4];

bool ok(int r, int c) { return maze[r][c] != '#'; }

int enc(int r, int c, int d) { return d*R*C + r*C + c; }
void dec(int s, int &r, int &c, int &d) {
  c = s % C; s /= C;
  r = s % R; 
  d = s / R;
}
int Enc(int r, int c, int p1, int p2) {
  return ((r*C + c)*RC + p1)*RC + p2;
}
void Dec(int S, int &r, int &c, int &p1, int &p2) {
  p2 = S % RC; S /= RC;
  p1 = S % RC; S /= RC;
  c = S % C; S /= C;
  r = S;
}

void solve(int P) {
  scanf("%d%d", &R, &C);
  int cr=-1, cc, mr=-1, mc;
  memset(maze, '#', sizeof(maze));
  for (int i = 1; i <= R; ++i) {
    scanf("%s", maze[i]+1);
    for (int j = 1; j <= C; ++j)
      if (maze[i][j] == 'X')  cr = i, cc = j;
      else if (maze[i][j] == 'O') mr = i, mc = j;
    maze[i][C+1] = '#';
  }
  assert(mr != -1 && cr != -1);
  ++R; ++C;
  ++R; ++C;
  RC = 4*R*C;

  for (int i = 1; i < R; ++i)
    for (int j = 1; j < C; ++j)
      if (maze[i][j] != '#') {
	for (int d = 0; d < 4; ++d) {
	  int ni = i, nj = j;
	  while (ok(ni, nj))
	    ni += dr[d], nj += dc[d];
	  nextwall[i][j][d] = enc(ni, nj, (d+2)%4);
	}
      }
  map<int, int> best;
  deque<int> q;
  int init = Enc(mr, mc, 0, 0);
  best[init] = 1;
  q.push_back(init);
  int res = 1<<28;
  while (!q.empty()) {
    int &S = q.front();
    q.pop_front();
    int dst = best[S];
    int r, c, p1, p2;
    Dec(S, r, c, p1, p2);
    if (r == cr && c == cc) { res <?= dst-1; break; }
    assert(maze[r][c] != '#');
    //    printf("[%d]: visit %d %d (portals %d %d)\n", dst ,r, c, p1, p2);
    // Walk
    for (int d = 0; d < 4; ++d) {
      int nr = r + dr[d], nc = c + dc[d];
      // Teleport
      if (p1 == enc(nr, nc, (d+2)%4) &&
	  p2 != 0) {
	int nd;
	dec(p2, nr, nc, nd);
	nr += dr[nd];
	nc += dc[nd];
	//	assert(ok(nr, nc));
      }

      if (ok(nr, nc)) {
	int NS = Enc(nr, nc, p1, p2);
	int &odst = best[NS];
	if (odst == 0 || odst > dst+1) {
	  odst = dst+1;
	  q.push_back(NS);
	}
      }
    }
    // Shoot
    for (int d = 0; d < 4; ++d) {
      int np = nextwall[r][c][d];
      if (np != p1 && np != p2) {
	int NS1 = Enc(r, c, np, p2);
	int &odst1 = best[NS1];
	if (odst1 == 0 || odst1 > dst) {
	  odst1 = dst;
	  q.push_front(NS1);
	}
	int NS2 = Enc(r, c, p1, np);
	int &odst2 = best[NS2];
	if (odst2 == 0 || odst2 > dst) {
	  odst2 = dst;
	  q.push_front(NS2);
	}
      }
    }
  }

  if (res < 1<<28)
    printf("Case #%d: %d\n", P, res);
  else
    printf("Case #%d: THE CAKE IS A LIE\n", P);
  fprintf(stderr, "%d yay %d %d %d\n", P, R, C, res);
}

int main() {
  int n;
  scanf("%d", &n);
  init();
  for (int i = 1; i <= n; ++i) solve(i);
  return 0;
}
