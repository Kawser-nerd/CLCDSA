#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXh 123
#define MAXw 123

int t, h,w;
int m[MAXh][MAXw];

int foi[MAXh][MAXw], nfoi;
int label[MAXh][MAXw];

int iof[MAXh*MAXw], niof;
int label_zero[MAXh*MAXw], nlabel_zero; /* label zero-indexed */

int dy[] = {-1, 0, 0, 1};
int dx[] = { 0,-1, 1, 0};

#define valid(y,x) \
  ((y >= 0) && (y < h) && \
   (x >= 0) && (x < w))

int DFS(int y, int x) {
  int i,k, yy,xx, minimo;

  if(foi[y][x] == nfoi)
    return label[y][x];

  foi[y][x] = nfoi;
  for(i=0,k=-1,minimo=m[y][x] ; i<4 ; i++) {
    yy = y+dy[i];
    xx = x+dx[i];

    if(valid(yy,xx) && m[yy][xx]<minimo) {
      minimo = m[yy][xx];
      k = i;
    }
  }

  if(k!=-1) label[y][x] = DFS(y+dy[k], x+dx[k]);
  return label[y][x];
}

int main() {
  int nt, i,j,k;

  memset(foi, 0, sizeof(foi));
  nfoi = 0;

  memset(iof, 0, sizeof(iof));
  niof = 0;

  scanf(" %d", &t);
  for(nt=1 ; nt<=t ; nt++) {
    nfoi++;
    niof++;

    scanf(" %d %d", &h, &w);

    k = 0;
    for(i=0 ; i<h ; i++)
      for(j=0 ; j<w ; j++) {
	scanf(" %d", &m[i][j]);
	label[i][j] = k++;
      }

    for(i=0 ; i<h ; i++)
      for(j=0 ; j<w ; j++)
	DFS(i,j);

    printf("Case #%d:\n", nt);

    nlabel_zero = 0;
    for(i=0 ; i<h ; i++) {
      for(j=0 ; j<w ; j++) {
	if(iof[label[i][j]] != niof) {
	  label_zero[label[i][j]] = nlabel_zero++;
	  iof[label[i][j]] = niof;
	}
	printf("%c ", label_zero[label[i][j]]+'a');
      }
      putchar('\n');
    }
  }

  return 0;
}
