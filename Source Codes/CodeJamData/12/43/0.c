#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

int in[2100], res[2100];

void solve(int st, int ed){
  int i, down=0;
  
  if(st >= ed) return;
  for(i=in[st]-1;i>st;i--) res[i] -= (++down);
  solve(st+1, in[st]-1);
  solve(in[st], ed);
}

int main(){
  int i,j,k,l,m,n;
  int size, count=0;
  int dame;

  scanf("%d",&size);
  while(size--){
    fprintf(stderr,"rest %d\n",size);
    scanf("%d",&n);
    rep(i,n-1) scanf("%d",in+i), in[i]--;

    printf("Case #%d:",++count);

    dame = 0;
    rep(i,n-1){
      REP(j,i+1,in[i]) if(in[j] > in[i]) dame = 1;
    }
    if(dame){ puts(" Impossible"); continue; }

    rep(i,n) res[i] = i*500000;
    solve(0,n-1);

    rep(i,n) printf(" %d",res[i]);
    puts("");
  }

  return 0;
}
