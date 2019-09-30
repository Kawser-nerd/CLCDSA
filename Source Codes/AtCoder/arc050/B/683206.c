#include<stdio.h>
long long R,B,x,y;
long long MIN(long long a,long long b){return a<b?a:b;}
long long f(long long a){
  if(a<0)a=0;
  long long b=R-x*a,c=B-a;
  if(a<0||b<0||c<0)return -1;
  return a+MIN(b,c/y);
}
int main(){
  long long m,l,r;
  scanf("%lld %lld %lld %lld",&R,&B,&x,&y);
  l=0;
  r=MIN(R/x,B);
  while(l-r){//printf("%lld %lld %lld %lld\n",l,r,f(m+1),f(m));
    m=(l+r)/2;//printf("%lld %lld %lld %lld\n",l,r,f(m+1),f(m));
    f(m+1)>f(m-1)?l=m+1:(r=m);
  }//printf("%lld %lld %lld %lld\n",f(-1),f(0),f(1),f(2));
  printf("%lld\n",f(l));
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:12:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld %lld %lld %lld",&R,&B,&x,&y);
   ^