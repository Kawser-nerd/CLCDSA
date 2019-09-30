#include<stdio.h>
int main(){
  int n,i;
  long long l[87]={2,1};
  scanf("%d",&n);
  for(i=2;i<=n;i++){
    l[i]=l[i-1]+l[i-2];
  }
  printf("%lld",l[n]);
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^