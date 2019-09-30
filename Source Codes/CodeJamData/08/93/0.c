#include<stdio.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

int x,y;
int mp[5][5];
int now[5][5];
int res;

int ok(int i,int j){
  int ii,jj;
  int nx,ny;
  int num=0;

  REP(ii,-1,2) REP(jj,-1,2){
    nx=i+ii; ny=j+jj;
    if(nx<0 || ny<0 || nx>=x || ny>=y) continue;
    if(now[nx][ny]) num++;
  }
  if(num == mp[i][j]) return 1; return 0;
}

void solve(int i,int j){
  int a,b,k,tmp;

  if(i==x){
    tmp=0;
    rep(a,x) rep(b,y) if(!ok(a,b)) return;
    rep(b,y) tmp += now[x/2][b];
    if(res < tmp) res = tmp;
    return;
  }

  if(j==y) {solve(i+1,0); return;}

  now[i][j]=1; if(!i || !j || ok(i-1,j-1)) solve(i,j+1);
  now[i][j]=0; if(!i || !j || ok(i-1,j-1)) solve(i,j+1);
}

int main(){
  int i,j,k,l,m,n;
  int size,count=0;

  scanf("%d",&size);
  while(size--){
    fprintf(stderr,"rest input = %d\n",size);
    res=0;
    scanf("%d%d",&x,&y);
    rep(i,x) rep(j,y) scanf("%d",mp[i]+j);
    solve(0,0);

    printf("Case #%d: %d\n",++count,res);
  }

  return 0;
}
