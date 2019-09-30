#include<stdio.h>

#define min(a,b) ((a)<(b)?(a):(b))
#define INF 2000000

int main(){
  int n,i,ans=INF;
  scanf("%d",&n);
  for(i=1;i<=n;i++){
    int tmp=n%i;
    tmp+=abs((n-tmp)/i-i);
    ans=min(ans,tmp);
  }
  printf("%d\n",ans);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:11:10: warning: implicit declaration of function ‘abs’ [-Wimplicit-function-declaration]
     tmp+=abs((n-tmp)/i-i);
          ^
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^