#include<stdio.h>
 
int main(void) {
  int i,j,N,M,Q;
  
  scanf("%d %d %d",&N,&M,&Q);
  
  int x[501][501] = {{0}};
  
  for(i=0; i<M;i++) {
    int l,r;
    scanf("%d %d",&l,&r);
    x[l][r]++;
  }
 
  for(i=1; i<=N; i++) {
    for(j=1; j<=N; j++) {
      x[i][j] = x[i][j] + x[i-1][j] + x[i][j-1] - x[i-1][j-1];
    }
  }
	
  for(i=0; i<Q; i++) {
    int p,q;
    scanf("%d %d",&p,&q);
    printf("%d\n",x[q][q] - x[p-1][q] - x[q][p-1] + x[p-1][p-1]);
  }
    
  return(0);
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d %d",&N,&M,&Q);
   ^
./Main.c:12:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d",&l,&r);
     ^
./Main.c:24:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d",&p,&q);
     ^