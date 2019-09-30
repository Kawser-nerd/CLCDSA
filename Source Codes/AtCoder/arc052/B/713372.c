#include<stdio.h>
#include<math.h>
#define PI acos(-1)
int MIN(int a,int b){return a<b?a:b;}
int MAX(int a,int b){return a<b?b:a;}
int main(){
  int n,m,a,b,i;
  int x[110],r[110],h[110];
  double ra,rb,s,ha,hb;
  scanf("%d %d",&n,&m);
  for(i=0;i<n;i++)scanf("%d %d %d",&x[i],&r[i],&h[i]);
  while(m--){
    s=0;
    scanf("%d %d",&a,&b);
    for(i=0;i<n;i++){
      if(x[i]>b||x[i]+h[i]<a)continue;
      ra=x[i]     <a?1.0*r[i]*(h[i]+x[i]-a)/h[i]:r[i];
      rb=x[i]+h[i]>b?1.0*r[i]*(h[i]+x[i]-b)/h[i]:0   ;
      ha=x[i]     <a?h[i]+x[i]-a:h[i];
      hb=x[i]+h[i]>b?h[i]+x[i]-b:0   ;
      s+=ra*ra*ha-rb*rb*hb;
    }
    printf("%f\n",s*PI/3.0);
  }
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:10:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d",&n,&m);
   ^
./Main.c:11:19: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i=0;i<n;i++)scanf("%d %d %d",&x[i],&r[i],&h[i]);
                   ^
./Main.c:14:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d",&a,&b);
     ^