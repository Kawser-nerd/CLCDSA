#include<stdio.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

char mp[100][100];
int x,y;
int opt[20][2000];

int sol(int d,int k){
  int i,j,m,res=0,tmp;
  int nk;
  int oku[20];

  if(d==x) return 0;
  if(opt[d][k]>=0) return opt[d][k];

  rep(m,1<<y){
    rep(i,y) if(m&(1<<i)) oku[i]=1; else oku[i]=0;
    rep(i,y) if(oku[i] && mp[d][i]=='x') break; if(i!=y) continue;
    rep(i,y) if(oku[i] && (k&(1<<i)) )   break; if(i!=y) continue;
    REP(i,1,y) if(oku[i-1] && oku[i]) break;    if(i!=y) continue;

    nk=0;
    rep(i,y){
      tmp=0;
      if(i && oku[i-1]) tmp=1;
      if(i<y-1 && oku[i+1]) tmp=1;
      if(tmp) nk ^= (1<<i);
    }

    tmp = sol(d+1,nk);
    rep(i,y) tmp += oku[i];
    if(res < tmp) res=tmp;
  }
  return opt[d][k]=res;
}

int main(){
  int i,j,k,l,m,n;
  int size,count=0;
  int res;
  
  scanf("%d",&size);
  while(size--){
    scanf("%d%d",&x,&y);
    rep(i,x) scanf("%s",mp[i]);

    rep(i,20) rep(j,2000) opt[i][j]=-1;
    res = sol(0,0);

    printf("Case #%d: %d\n",++count,res);
  }

  return 0;
}
