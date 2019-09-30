#include<stdio.h>
#include<string.h>

#define OUTSTREAM stdout

int N,R,H,W;

int board[101][101];
int px[2]={2,1}, py[2]={1,2};


void init() {
  int i,j;
  for (i=0;i<101;i++)
    for (j=0;j<101;j++)
      board[i][j] = 0;
  board[0][0]=1;
}

long solve() {
  int i,j,k;

  for (i=0;i<H;i++)
    for (j=0;j<W;j++) {
      if (board[i][j] <= 0)
	continue;
      for (k=0;k<2;k++) {
	if (i+px[k]>=H || j+py[k] >=W)
	  continue;
	if (board[i+px[k]][j+py[k]] == -1)
	  continue;
	board[i+px[k]][j+py[k]] +=board[i][j];
	board[i+px[k]][j+py[k]] %= 10007;
      }
    }
  return board[H-1][W-1];
}

void main() {
  FILE *in=fopen("input.txt","r");
  FILE *out=fopen("output.txt","w");
  long i,j;
  int x,y;
  long min;
  
  fscanf(in,"%d",&N);
  for (i=0;i<N;i++) {
    fscanf(in,"%d %d %d",&H,&W,&R);
    init();
    for (j=0;j<R;j++) {
      fscanf(in,"%d %d",&x,&y);
      board[x-1][y-1]=-1;
    }
    min=solve();

    fprintf(OUTSTREAM,"Case #%ld: %ld\n",i+1, min);
  }
}
