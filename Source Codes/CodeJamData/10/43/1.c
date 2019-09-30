#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

#define N 200
int now[N][N], next[N][N];

int main(){
  int i,j,k,l,m,n,res;
  int x1,y1,x2,y2;
  int size,count=0;

  scanf("%d",&size);
  while(size--){
    scanf("%d",&n);
    rep(i,N) rep(j,N) now[i][j]=0;
    rep(k,n){
      scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
      REP(i,x1,x2+1) REP(j,y1,y2+1) now[i][j]=1;
    }
    n=1; res=0;
    while(n){
      res++; n=0;
      rep(i,N) rep(j,N) next[i][j]=0;
      REP(i,1,N) REP(j,1,N){
        if( now[i][j] && (now[i-1][j] || now[i][j-1])) next[i][j]=1, n++;
        if(!now[i][j] && (now[i-1][j] && now[i][j-1])) next[i][j]=1, n++;
      }
      rep(i,N) rep(j,N) now[i][j]=next[i][j];
    }

    printf("Case #%d: %d\n",++count,res);
  }

  return 0;
}
