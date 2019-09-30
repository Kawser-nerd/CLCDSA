#include<stdio.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

int s[2000];
int num[2000][2000], type[2000][2000];

int opt;
int res[2000],tmp[2000];

int main(){
  int i,j,k,l,m,n,t,ok;
  int a,b,c;

  int size,count=0;
  scanf("%d",&size);
  while(size--){
    scanf("%d%d",&n,&m);
    rep(i,m){
      scanf("%d",s+i);
      rep(j,s[i]) {scanf("%d%d",num[i]+j,type[i]+j); num[i][j]--;}
    }

    opt = n+1;
    rep(k,(1<<n)){
      t=0; rep(i,n) if(k&(1<<i)) tmp[i]=1, t++; else tmp[i]=0;
      if(opt <= t) continue;
      rep(i,m){
        rep(j,s[i]) if(tmp[num[i][j]]==type[i][j]) break;
        if(j==s[i]) break;
      }
      if(i==m){
        opt=t;
        rep(i,n) res[i]=tmp[i];
      }
    }

    printf("Case #%d:",++count);
    if(opt>n) puts(" IMPOSSIBLE");
    else {
      rep(i,n) printf(" %d",res[i]); puts("");
    }
  }

  return 0;
}
