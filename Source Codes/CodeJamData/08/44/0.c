#include<stdio.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

char in[60000];
int len,k,per;

int opt[16][70000][16];
int pre[16][16];

int solve(int st,int p,int last){
  int i,j,res=0,tmp;

  if(opt[st][p][last]>=0) return opt[st][p][last];

  if(p==0){
    REP(i,1,per) if(in[(i-1)*k+last]==in[i*k+st]) res++;
    opt[st][p][last]=res; return res;
  }

  rep(i,k) if(p&(1<<i)){
    tmp = solve(st,p^(1<<i),i);
    tmp += pre[last][i];
    if(res<tmp) res=tmp;
  }

  opt[st][p][last]=res; return res;
}

int main(){
  int i,j,l,m,n,p;
  int a,b;
  int res;
  int size,count=0;

  scanf("%d",&size);
  while(size--){
    fprintf(stderr,"%d\n",size);
    scanf("%d%s",&k,in);
    for(i=0;;i++) if(in[i]<' ') break; len=i;
    per = len/k;

    rep(a,k) rep(b,k){
      pre[a][b]=0;
      rep(j,per) if(in[j*k+a]==in[j*k+b]) pre[a][b]++;
    }

    res=0; p=(1<<k)-1;
    rep(i,k) rep(j,p) rep(m,k) opt[i][j][m]=-1;
    rep(i,k){
      j = solve(i,p^(1<<i),i);
      if(res<j) res=j;
    }
    
    printf("Case #%d: %d\n",++count,len-res);
  }
  
  return 0;
}
