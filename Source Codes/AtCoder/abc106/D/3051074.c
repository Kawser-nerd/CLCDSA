#include <stdio.h>

int main(void){
  int i,j,ans;
  int n,m,Q,L,R;
  int train[501][501],p,q;
  int ruiseki[501][501];
  
  scanf("%d %d %d",&n,&m,&Q);
  
  /*??????????*/
  for(i=0; i<=n; i++) for(j=0; j<=n; j++) train[i][j] = 0;
  
  /*????????????*/
  for(i=0; i<=n; i++) for(j=0; j<=n; j++) ruiseki[i][j] = 0;

  /*???????*/
  for(i=0;i<m;i++){
    scanf("%d %d",&L,&R);
    //printf("LEFT->%d. RIGHT->%d\n",L,R);
    train[L][R]++;
  }
  
  /*2??????????*/
  for(i=1; i<=n; i++) for(j=1; j<=n; j++){
    ruiseki[i][j] = ruiseki[i-1][j] + ruiseki[i][j-1] - ruiseki[i-1][j-1] + train[i][j];
  }
  
  //?????
  for(i=0;i<Q;i++){
    scanf("%d %d",&p,&q);
    ans = ruiseki[q][q] + ruiseki[p-1][p-1] - ruiseki[q][p-1] - ruiseki[p-1][q];
    printf("%d\n",ans);
  }
  
  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:9:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d %d",&n,&m,&Q);
   ^
./Main.c:19:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d",&L,&R);
     ^
./Main.c:31:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d",&p,&q);
     ^