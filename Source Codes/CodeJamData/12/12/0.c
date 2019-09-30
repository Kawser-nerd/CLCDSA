#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

int main(){
  int i,j,k,l,m,n,res,now,ok;
  int a[1200], b[1200], alr[1200];
  int size, count = 0;

  scanf("%d",&size);
  while(size--){
    printf("Case #%d: ",++count);
    
    scanf("%d",&n);
    rep(i,n) scanf("%d%d",a+i,b+i);
    rep(i,n) alr[i] = 0;

    res = 0;
    now = 0;
    for(;;){
      if(now==2*n) break;

      ok = 0;
      rep(i,n) if(alr[i]!=2 && b[i]<=now){
        res++;
        now += 2 - alr[i];
        alr[i] = 2;
        ok = 1;
      }
      if(ok) continue;

      k = -1;
      rep(i,n) if(alr[i]==0 && a[i]<=now){
        if(k==-1){ k = i; continue; }
        if(b[i] > b[k]) k = i;
      }
      if(k==-1){res=-1; break;}

      alr[k]=1;
      res++;
      now++;
    }

    if(res==-1) puts("Too Bad"); else printf("%d\n",res);

  }

  return 0;
}
