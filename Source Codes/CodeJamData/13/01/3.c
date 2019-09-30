#include <stdio.h>

#define DIM 4

#define UNKNOWN 0
#define PLAYERX 1
#define PLAYERO 2
#define DRAW    3
#define INC     4

char m[DIM][DIM+1];

int verify(int y, int x, int incy, int incx) {
  int nx, no, nt;

  nx = no = nt = 0;
  while (1) {    
    if (x<0 || y<0 || x>=DIM || y>=DIM) break;
    if (m[y][x]=='X') nx++;
    else if (m[y][x]=='O') no++;
    else if (m[y][x]=='T') nt++;
    y+=incy; x += incx;
  }

  if (nx + nt == DIM) return PLAYERX;
  if (no + nt == DIM) return PLAYERO;
  return UNKNOWN;
}

int solve() {
  int i, j, aux;

  for (i=0; i<DIM; i++) {
    aux = verify(i, 0, 0, 1);
    if (aux!=UNKNOWN) return aux;
    aux = verify(0, i, 1, 0);
    if (aux!=UNKNOWN) return aux;
  }
  
  aux = verify(0, 0, 1, 1);
  if (aux!=UNKNOWN) return aux;

  aux = verify(0, DIM-1, 1, -1);
  if (aux!=UNKNOWN) return aux;

  for (i=0; i<DIM; i++)
    for (j=0; j<DIM; j++)
      if (m[i][j]=='.') return INC;

  return DRAW;
}

int main() {
  int ncases, i, j, res;

  scanf("%d", &ncases);
  for (i=1; i<=ncases; i++) {
    for (j=0; j<DIM; j++) scanf("%s", m[j]);

    res = solve();
    printf("Case #%d: ", i);
    
    if (res==PLAYERX)      puts("X won");
    else if (res==PLAYERO) puts("O won");
    else if (res==DRAW)    puts("Draw");
    else                   puts("Game has not completed");
  }

  return 0;
}
