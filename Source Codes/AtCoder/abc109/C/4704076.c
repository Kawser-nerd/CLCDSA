#include <stdio.h>
#define abs(a) ((a)>(0)?(a):-(a))
int gcd(int *sub,int n){
  int a,b,c;
  if(n>1)a=gcd(sub,n-1);
  else a=sub[0];
  b=sub[n];
  if (a<b) {
    a+=b; b=a-b; a-=b;
  }
  while (b!=0) {
    c=a%b; a=b; b=c;
  }
  return a;
}
int main(){
  int n,i,X;
  scanf("%d%d",&n,&X);
  int x[n],sub[n];
  for(i=0;i<n;i++)scanf("%d",&x[i]);
  for(i=0;i<n;i++)sub[i]=abs(x[i]-X);
  printf("%d",gcd(sub,n-1));
} ./Main.c: In function ‘main’:
./Main.c:18:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&n,&X);
   ^
./Main.c:20:19: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i=0;i<n;i++)scanf("%d",&x[i]);
                   ^