#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

void unionInit(int d[],int s){int i;rep(i,s)d[i]=i;}
int unionGet(int d[],int n){int t=n,k;while(d[t]!=t)t=d[t];while(d[n]!=n)k=d[n],d[n]=t,n=k;return n;}
int unionConnect(int d[],int a,int b){a=unionGet(d,a);b=unionGet(d,b);if(a==b)return 0;d[a]=b;return 1;}

int main(){
  int i,j,k,l,m,n;
  int ind[10000], use[10000], go[10000];
  int mp[100][100];
  int dx[4]={-1,0,0,1}, dy[4]={0,-1,1,0};
  int x,y,sx,sy,nx,ny,xy;
  int size,count=0;

  scanf("%d",&size);
  while(size--){
    scanf("%d%d",&x,&y); xy=x*y;
    rep(i,x) rep(j,y) scanf("%d",mp[i]+j);
    unionInit(ind,xy);

    rep(i,x) rep(j,y){
      nx=i; ny=j;
      rep(k,4){
        sx=i+dx[k]; sy=j+dy[k];
        if(sx<0||sy<0||sx>=x||sy>=y) continue;
        if(mp[nx][ny] > mp[sx][sy]) nx=sx, ny=sy;
      }
      unionConnect( ind,i*y+j,nx*y+ny );
    }

    printf("Case #%d:\n",++count);
    rep(i,xy) use[i]=-1; k=0;
    rep(i,x) rep(j,y){
      m=unionGet(ind,i*y+j);
      if(use[m]==-1) use[m]=k++;
      printf("%c",(char)('a'+use[m]));
      if(j+1<y) putchar(' '); else putchar('\n');
    }
  }

  return 0;
}
