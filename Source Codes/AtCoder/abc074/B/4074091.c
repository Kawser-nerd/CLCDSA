#include<stdio.h>
int main(){
  int n,k,x[100],i,A=0;
  scanf("%d%d",&n,&k);
  for(i=0;i<n;i++){
    scanf("%d",&x[i]);
    A+=x[i]<k-x[i]?x[i]:k-x[i];
  }
  printf("%d",A*2);
} ./Main.c: In function ‘main’:
./Main.c:4:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&n,&k);
   ^
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&x[i]);
     ^