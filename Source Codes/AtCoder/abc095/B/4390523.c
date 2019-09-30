#include <stdio.h>
int main(void){
  int n,x,m[101],i,sum=0,min=9999999;
  scanf("%d%d",&n,&x);
  for(i=0;i<n;i++){
    scanf("%d",&m[i]);
    if(min>m[i]) min=m[i];
    sum+=m[i];
  }
  int count=n;
  x-=sum;
  count+=(x/min);
  printf("%d",count);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&n,&x);
   ^
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&m[i]);
     ^