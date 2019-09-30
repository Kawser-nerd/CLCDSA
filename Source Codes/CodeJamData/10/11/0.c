#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

int n, m;
char in[60][60], tmp[60][60];

int solve(char c){
  int i,j,k,dx,dy;
  int ni, nj;

  rep(i,n) rep(j,n) REP(dx,-1,2) rep(dy,2) if(dx||dy){
    k=0;
    ni=i; nj=j;
    for(;;){
      if(ni<0||nj<0||ni>=n||nj>=n||in[ni][nj]!=c) break;
      k++; ni+=dx; nj+=dy;
    }
    if(k >= m) return 1;
  }
  return 0;
}

int main(){
  int i,j,k,l;
  int fg1, fg2;
  int size,count=0;

  scanf("%d",&size);
  while(size--){
    scanf("%d%d",&n,&m);
    rep(i,n) scanf("%s",tmp[i]);

    rep(i,n) rep(j,n) in[j][n-1-i]=tmp[i][j];

    rep(j,n){
      k=n-1;
      for(i=n-1;i>=0;i--) if(in[i][j]!='.') in[k][j]=in[i][j], k--;
      while(k>=0) in[k][j]='.', k--;
    }

    fg1 = solve('R');
    fg2 = solve('B');

    printf("Case #%d: ",++count);
    if( fg1 &&  fg2) puts("Both");
    if( fg1 && !fg2) puts("Red");
    if(!fg1 &&  fg2) puts("Blue");
    if(!fg1 && !fg2) puts("Neither");
  }

  return 0;
}
