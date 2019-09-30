#include<stdio.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

#define N 50
#define INF 1000000000

int x,y;
int sx,sy;
int opt;
int mp[N][N];

int dx[4]={-1,0,0,1}, dy[4]={0,-1,1,0};

void solve(int depth){
  int i,j,k,d;
  int ni,nj;
  int cp[N][N];

  if(mp[sx][sy]<=0) return;
  if(opt < depth) opt = depth;

  k=0;
  rep(d,4){
    ni = sx+dx[d]; nj = sy+dy[d];
    if(ni<0 || nj<0 || ni>=x || nj>=y) continue;
    if(mp[ni][nj] > 0) k++;
  }
  if(k==0) {opt=INF; return;}
  if(opt==INF) return;

/*  printf("depth %d, rest %d\n",depth,k);
  rep(i,x){rep(j,y) printf("%03d ",mp[i][j]); puts("");}
*/
  rep(i,x) rep(j,y) cp[i][j]=mp[i][j];
  rep(i,x) rep(j,y){
    if(i==sx && j==sy) continue;
    if(cp[i][j]<=0) continue;

    k=0;
    rep(d,4){
      ni = i+dx[d]; nj = j+dy[d];
      if(ni<0 || nj<0 || ni>=x || nj>=y) continue;
      if(k < cp[ni][nj]) k=cp[ni][nj];
    }
    if(k==0) continue;
    rep(d,4){
      ni = i+dx[d]; nj = j+dy[d];
      if(ni<0 || nj<0 || ni>=x || nj>=y) continue;
      if(k == cp[ni][nj]) {mp[ni][nj] -= cp[i][j]; break;}
    }
  }

  solve(depth+1);
  rep(d,4){
    ni = sx+dx[d]; nj = sy+dy[d];
    if(ni<0 || nj<0 || ni>=x || nj>=y) continue;
    mp[ni][nj] -= cp[sx][sy];
    solve(depth+1);
    mp[ni][nj] += cp[sx][sy];
  }

  rep(i,x) rep(j,y) mp[i][j]=cp[i][j];
}

int main(){
  int i,j,k,l,m,n;
  int size,count=0;

  scanf("%d",&size);
  while(size--){
    scanf("%d%d%d%d",&y,&x,&sy,&sx); sx--; sy--;
    rep(i,x) rep(j,y) scanf("%d",mp[i]+j);
    opt=0; solve(0);

    printf("Case #%d: ",++count);
    if(opt >= INF) puts("forever");
    else printf("%d day(s)\n",opt);
  }

  return 0;
}
