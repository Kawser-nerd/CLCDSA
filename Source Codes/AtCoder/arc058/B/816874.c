#include<stdio.h>
int mbk(long long a,int n,int m){return n?(mbk((a*a)%m,n/2,m)*(n%2?a:1))%m:1;}
int inv(int a,int m){return mbk((long long)a,m-2,m);}
int aCb(int a,int b,int m){
  long long s=1,i;
  if(b>a-b)b=a-b;
  for(i=0;i<b;i++)s=(((s*(a-i))%m)*inv(i+1,m))%m;  
  return (int)s;
}
int main(){
  int h,w,a,b,i,M=1e9+7;
  long long s=0,ans=0,n=1,m=1;
  scanf("%d %d %d %d",&h,&w,&a,&b);
  for(i=0;i<h+w-b-i-2;i++)m=(m*i)%M;
  m=aCb(h+w-b-2,w-b-1,M);//printf("%d %d %lld\n",h+w-b-2,w-b-1,m);
  for(i=0;i<h-a;i++){//printf("%lld %lld\n",n,m);
    s=(n*m)%M;
    ans=(ans+s)%M;
    n=(n*inv(i+1,M))%M;
    n=(n*(b+i))%M;
    m=(m*inv(h+w-i-b-2,M))%M;
    m=(m*(h-i-1))%M;
    //n=(n*aCb(h-i+w-b-2,w-b-1,M))%M;
    //printf("%d %d %d %d %lld\n",b+i-1,i,h-i+w-b-2,w-b-1,n);
    //s=(s+n)%M;//printf("%lld\n",s);
  }
  printf("%lld\n",ans);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:13:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d %d %d",&h,&w,&a,&b);
   ^