#include <stdio.h>
int main (){
int n,d,x,i,sum,k;
  scanf ("%d%d%d",&n,&d,&x);
  for (i=0;i<n;i++){
    scanf ("%d",&k);
  sum=sum+(d-1)/k+1;
  }
  sum=sum+x;
  printf ("%d",sum);
return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf ("%d%d%d",&n,&d,&x);
   ^
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf ("%d",&k);
     ^