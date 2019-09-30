#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
int main(void){
  int n,i,j,T,c[110],t[110],tm[110],cost[110],k=0;
  scanf("%d%d",&n,&T);
  for(i=0;i<n;i++){
    scanf("%d %d",&c[i],&t[i]);
    if(t[i]<=T) {tm[k]=t[i];cost[k]=c[i];k++;}
  }
  if(tm[0]=='\0') {printf("TLE");return 0;}
  int min=cost[0];
  for(i=1;i<k;i++){
    if(min>cost[i]) min=cost[i];
  }
  printf("%d",min);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&n,&T);
   ^
./Main.c:9:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d",&c[i],&t[i]);
     ^