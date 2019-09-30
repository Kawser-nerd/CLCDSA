#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

int n,mx,opt;
int edge[120][120];
int ok[120][120];

void solve(int d){
  int i,j,k,fg=0;

  if(mx>=opt) return;
  if(d==n){opt=mx; return;}

  rep(i,mx+1) if(ok[d][i]==0){
    if(i==mx) fg=1; else fg=0;
    REP(j,d+1,n) if(edge[d][j]) ok[j][i]++;
    if(fg) mx++;
    solve(d+1);
    if(fg) mx--;
    REP(j,d+1,n) if(edge[d][j]) ok[j][i]--;
  }
  
}

int main(){
  int i,j,k,l,m,K;
  int in[120][120];
  int size,count=0;

  long long a,b;

  scanf("%d",&size);
  while(size--){
    scanf("%d%d",&n,&K);
    rep(i,n) rep(j,K) scanf("%d",in[i]+j);

    rep(i,n) rep(j,n) edge[i][j]=0;
    REP(k,1,K){
      rep(i,n) REP(j,i+1,n){
        a=in[i][k-1]-in[j][k-1];
        b=in[i][k  ]-in[j][k  ];
        if(a*b<=0) edge[i][j]=edge[j][i]=1;
      }
    }

    mx=0; opt=n;
    rep(i,120) rep(j,120) ok[i][j]=0;
    solve(0);

    printf("Case #%d: %d\n",++count,opt);
  }

  return 0;
}
