#include<stdio.h>
int main(){
  long n,a,b,ans;
  scanf("%d%ld%ld",&n,&a,&b);
  if(b<a) ans=0;
  else if(n==1){
    if(a!=b) ans=0;
    else ans=1;
  }
  else {
    ans=(n-2)*(b-a)+1;
  }
  printf("%ld",ans);
} ./Main.c: In function ‘main’:
./Main.c:4:9: warning: format ‘%d’ expects argument of type ‘int *’, but argument 2 has type ‘long int *’ [-Wformat=]
   scanf("%d%ld%ld",&n,&a,&b);
         ^
./Main.c:4:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%ld%ld",&n,&a,&b);
   ^