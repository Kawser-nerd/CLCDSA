#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

#define ll long long
void llSort(ll d[],int s){int i,j;ll k,t;if(s<=1)return;k=(d[0]+d[s-1])/2;i=-1;j=s;for(;;){while(d[++i]<k);while(d[--j]>k);if(i>=j)break;t=d[i];d[i]=d[j];d[j]=t;}llSort(d,i);llSort(d+j+1,s-j-1);}

int N;
ll my, in[39], init[39];

double calc(void){
  int i, k;
  double res = 0;
  REP(k,1,N) if(in[k-1] != in[k]) break;

  rep(i,k) res += in[i] - init[i];
  res *= 36.0 / k;

  rep(i,N) res -= in[i] - init[i];

  return res;
}

int main(){
  int i,j,k,l,m;
  double res, tmp;
  ll go, per, mx;
  int size, count = 0;

  scanf("%d",&size);
  while(size--){
    scanf("%lld%d",&my,&N);
    rep(i,37) in[i] = 0;
    rep(i,N) scanf("%lld",in+i);
    N = 37;
    llSort(in, N);

    rep(i,N) init[i] = in[i];

    res = 0;
    for(;;){
      REP(k,1,N) if(in[k-1] != in[k]) break;
      if(k==N) break;
      
      per = (my-k) / k;
      mx = in[k] - in[k-1] - 2;
      if(per > mx) per = mx;
      if(per > 1) rep(i,k) in[i] += per, my -= per;

      if(per <= 1){
        if(!my) break;
        in[k-1]++; my--;
      }
      
      tmp = calc();
      if(res < tmp) res = tmp;
    }

    printf("Case #%d: %.10f\n", ++count,res);
  }

  return 0;
}
