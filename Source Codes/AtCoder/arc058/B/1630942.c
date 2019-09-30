#include<stdio.h>
long long d[200010]={1};
int mbk(long long a,int n,int m){return n?(mbk((a*a)%m,n/2,m)*(n%2?a:1))%m:1;}
int inv(int a,int m){return mbk((long long)a,m-2,m);}
int aCb(int a,int b,int m){return d[a]*inv(d[b],m)%m*inv(d[a-b],m)%m;}
int main(){
  int h,w,a,b,M=1e9+7,s=0,i;
  for(i=0;i<200000;i++)d[i+1]=(d[i]*(i+1LL))%M;
  scanf("%d %d %d %d",&h,&w,&a,&b);
  for(i=0;i<h-a;i++)s=(s+(1LL*aCb(i+b-1,i,M)*aCb(w-b+h-i-2,w-b-1,M))%M)%M;
  printf("%d\n",s);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:9:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d %d %d",&h,&w,&a,&b);
   ^