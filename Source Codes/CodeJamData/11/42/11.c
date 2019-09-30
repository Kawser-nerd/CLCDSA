#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int T, R, C, D;
int grid[10][10];

int valid(int j, int k, int K) {
  double cx = ((double)j) + ((double)K)/2;
  double cy = ((double)k) + ((double)K)/2;
  double ansx = 0.0, ansy = 0.0;
  

  int a,b;
  for(a=0; a<K; a++) 
    for(b=0; b<K; b++) {
      if(a==0 && b==0)
	continue;
      if(a==0 && b==(K-1))
	continue;
      if(a==(K-1) && b==0)
	continue;
      if(a==(K-1) && b==(K-1))
	continue;
      ansx += ((double) grid[a+j][b+k])*((double)(j+a)+0.5 - cx);
      ansy += ((double) grid[a+j][b+k])*((double)(k+b)+0.5 - cy);
    }

  if(fabs(ansx)<0.00000001 && fabs(ansy)<0.000000001)
    return 1;
  return 0;
}

int main() {

  int i,j,k, K, maxK;

  scanf("%d", &T);
  
  for(i=1; i<=T; i++) {
    scanf("%d %d %d", &R, &C, &D);
    //printf("R=%d, C=%d, D=%d\n", R, C, D);

    for(j=0; j<R; j++) {
      char buffer[10000];
      scanf(" %s", buffer);
      for(k=0; k<C; k++)
	grid[j][k] = buffer[k]-'1' + 1;
    }
    maxK = -1;

    for(K=3; K<=10; K++)
      for(j=0; j<=(R-K); j++)
	for(k=0; k<=(C-K); k++)
	  if(valid(j,k,K)) {
	    maxK = K;
	    //printf("%d, %d, %d is valid\n", j,k,K);
	  }
    if(maxK==-1)
      printf("Case #%d: IMPOSSIBLE\n", i);
    else
      printf("Case #%d: %d\n", i, maxK);
  }
  
  
  
}
