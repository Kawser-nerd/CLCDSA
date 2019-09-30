/* GCJ'09 Template v.1e-9
 * Per Austrin
 */
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cassert>
#include <cctype>
#include <vector>
#include <map>
#include <set>

using namespace std;

typedef long long ll;

void init(int N) {
}

const int dr[] = {-1,0,0,1};
const int dc[] = {0,-1,1,0};

int alt[500][500];
int dir[500][500];
char reg[500][500];
char nextreg;

int Reg(int r, int c) {
  if (reg[r][c]) return reg[r][c];
  if (dir[r][c] != -1) 
    reg[r][c] = Reg(r + dr[dir[r][c]], c + dc[dir[r][c]]);
  else
    reg[r][c] = nextreg++;
  return reg[r][c];
}

void solve(int P) {

  int W, H;
  scanf("%d%d", &H, &W);
  for (int i = 0; i < H; ++i)
    for (int j = 0; j < W; ++j)
      scanf("%d", alt[i]+j);

  for (int i = 0; i < H; ++i)
    for (int j = 0; j < W; ++j) {
      dir[i][j] = -1;
      int h = alt[i][j];
      for (int d = 0; d < 4; ++d) {
	int ni = i + dr[d], nj = j + dc[d];
	if (ni >= 0 && nj >= 0 && ni < H && nj < W && alt[ni][nj] < h)
	  dir[i][j] = d, h = alt[ni][nj];
      }
      //      printf("dir %d %d = %d, h %d\n", i, j, dir[i][j], h);
    }
  memset(reg, 0, sizeof(reg));
  nextreg = 'a';

  printf("Case #%d:\n", P);
  for (int i = 0; i < H; ++i) 
    for (int j = 0; j < W; ++j)
      printf("%c%c", Reg(i, j), j==W-1 ? '\n' : ' ');

}

int main(void) {
  int N;
  scanf("%d", &N);
  init(N);
  for (int i = 1; i <= N; ++i) solve(i);
  return 0;
}
