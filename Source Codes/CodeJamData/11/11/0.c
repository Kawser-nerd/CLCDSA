#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

#define ll long long

int main(){
  int i,j,k,l,m; ll n;
  int x,y;
  int size,count=0;
  int is_can[101][101] = {};

  REP(i,1,101) rep(j,i+1){
    k = j*100;
    if(k%i) continue;
    k/=i;
    REP(m,i,101) is_can[m][k] = 1;
  }

  scanf("%d",&size);
  while(size--){
    scanf("%lld%d%d",&n,&x,&y);
    printf("Case #%d: ",++count);

    if(x<100 && y==100){ puts("Broken"); continue; }
    if(x>  0 && y==  0){ puts("Broken"); continue; }

    if(n>100) n = 100;
    if(is_can[n][x]) puts("Possible"); else puts("Broken");
  }

  return 0;
}
