#include<stdio.h>
#include<stdlib.h>
int main(){
  int n,a=0,b=0,d[100010],i;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&d[i]);
    if(a<d[i])a=d[i];
  }
  for(i=0;i<n;i++){
    if(abs(a/2-d[i])<abs(a/2-b))b=d[i];
  }
  printf("%d %d\n",a,b);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&d[i]);
     ^