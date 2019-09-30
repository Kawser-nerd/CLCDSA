#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

#define ll long long

int getPrime(int n,int p[]){int i,j,n2=n/2;rep(i,n2)p[i]=1;for(i=3;i*i<n;i+=2)if(p[i>>1])for(j=(i*i)>>1;j<n2;j+=i)p[j]=0;j=1;p[0]=2;REP(i,1,n2)if(p[i])p[j++]=i*2+1;return j;}
int ps, p[1000000];

int main(){
  int i,j,k,l,m;
  ll n, np, mul;
  int size, count=0, res;

  ps = getPrime(1000000,p);

  scanf("%d",&size);
  while(size--){
    fprintf(stderr,"size %d\n",size);

    scanf("%lld",&n);
    res = 0;

    rep(i,ps){
      np = p[i];
      if(np*np > n) break;

      mul = np;
      for(;;){
        mul *= np;
        if(mul > n) break;
        res++;
      }
    }

    if(n > 1) res++;
    printf("Case #%d: %d\n",++count,res);
  }

  return 0;
}
