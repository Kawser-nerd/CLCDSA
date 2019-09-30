#include<stdio.h>

#define OUTSTREAM stdout

int N,M,V;
int changable[10001];
int minChg[2][10001];
int type[10001];

int tryChg(int l, int r, int p, int add) {
  int nChg = minChg[l][p*2] + minChg[r][p*2+1] + add;
  int result;
  if ((type[p]+add)%2 == 1) { // AND
    result = l & r;
  }
  else {
    result = l | r;
  }

  if (minChg[result][p] > nChg) {
    minChg[result][p]= nChg;
  }

  return;
}

void print() {
  int j;
  return;
  for (j=1;j<=M;j++)
    printf("(%d, %d)\n",minChg[0][j],minChg[1][j]);

  printf("\n");
}

int getMin() {
  int k;
  int lIdx, rIdx;
  int j;
  int nChg;

  for (j=(M-1)/2; j>=1; j--) {
    for (k=0;k<4;k++) {
      lIdx = k/2;
      rIdx = k%2;

      if (minChg[lIdx][j*2] == 99999 ||
	  minChg[rIdx][j*2+1] == 99999)
	continue;

      nChg = tryChg (lIdx, rIdx, j, 0);
      if (changable[j])
	nChg = tryChg (lIdx, rIdx, j, 1);
    }

    print();
  }

  return minChg[V][1];
}

void main() {
  FILE *in=fopen("input.txt","r");
  FILE *out=fopen("output.txt","w");
  long i,j;
  int tmp, min;
  
  fscanf(in,"%d",&N);
  for (i=0;i<N;i++) {
    fscanf(in,"%d %d",&M, &V);
    
    for (j=1;j<=(M-1)/2;j++) {
      minChg[0][j] = 99999;
      minChg[1][j] = 99999;
      fscanf(in,"%d %d", &type[j], &changable[j]);
    }

    for (j=1;j<=(M+1)/2;j++) {
      fscanf(in,"%d",&tmp);
      minChg[0][j+(M-1)/2] = minChg[1][j+(M-1)/2] = 99999;
      minChg[tmp][j+(M-1)/2] = 0;
    }
    
    print();
    min=getMin();
    
    fprintf(OUTSTREAM,"Case #%ld: ",i+1);
    if (min == 99999)
      fprintf(OUTSTREAM, "IMPOSSIBLE\n");
    else
      fprintf(OUTSTREAM, "%d\n", min);
  }
}
