#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

#define INF 1000000000

int main(){
  int i,j,k,l,m,n,mask;
  int size, count = 0;
  
  int from[10000], to[10000], mn[10000], mx[10000], dist[1000];
  int q[10000], qs;

  int mat[50][50];
  int ok[10000];

  scanf("%d",&size);
  while(size--){
    fprintf(stderr,"rest %d\n",size);
    
    scanf("%d%d%d",&n,&m,&qs);
    rep(i,m) scanf("%d%d%d%d",from+i,to+i,mn+i,mx+i), from[i]--, to[i]--;
    rep(i,qs) scanf("%d",q+i), q[i]--;

    printf("Case #%d: ",++count);

    rep(i,m) ok[i] = 0;
    rep(mask, 1<<m){
      rep(i,n) rep(j,n) mat[i][j] = INF;
      rep(i,n) mat[i][i] = 0;
      rep(i,m){
        dist[i] = mn[i];
        if(mask&1<<i) dist[i] = mx[i];
      }
      rep(i,m) if(mat[from[i]][to[i]] > dist[i]) mat[from[i]][to[i]] = dist[i];

      rep(k,n) rep(i,n) rep(j,n) if(mat[i][j] > mat[i][k]+mat[k][j]) mat[i][j] = mat[i][k]+mat[k][j];

      rep(i,m){
        if(mat[0][1] == mat[0][from[i]] + dist[i] + mat[to[i]][1]) ok[i]++;
      }
    }


    rep(i,qs) if(!ok[q[i]]) break;
    if(i==qs) puts("Looks Good To Me");
    else      printf("%d\n",q[i]+1);
  }

  return 0;
}
