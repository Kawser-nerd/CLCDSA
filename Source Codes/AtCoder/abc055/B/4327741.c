#include<stdio.h>
int main(){
  long long n,i,p=1;
  scanf("%d",&n);
  for(i=1;i<=n;i++){
    p=(p*i)%1000000007;
  }
  printf("%lld",p);
} ./Main.c: In function ‘main’:
./Main.c:4:9: warning: format ‘%d’ expects argument of type ‘int *’, but argument 2 has type ‘long long int *’ [-Wformat=]
   scanf("%d",&n);
         ^
./Main.c:4:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^