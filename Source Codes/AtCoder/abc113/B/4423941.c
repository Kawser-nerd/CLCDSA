#include <stdio.h>
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define abs(a) ((a)>(0)?(a):-(a))
int main(){
  int n;
  double t,a;
  scanf("%d%lf %lf",&n,&t,&a);
  int h[n],ans=1,i;
  double sub,buf;
  for(i=0;i<n;i++)scanf("%d",&h[i]);
  sub=abs(a-(t-h[0]*0.006));
  for(i=1;i<n;i++){
    buf=sub;
    sub=min(sub,abs(a-(t-h[i]*0.006)));
    if(buf!=sub)ans=i+1;
  }
  printf("%d",ans);
} ./Main.c: In function ‘main’:
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%lf %lf",&n,&t,&a);
   ^
./Main.c:11:19: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i=0;i<n;i++)scanf("%d",&h[i]);
                   ^