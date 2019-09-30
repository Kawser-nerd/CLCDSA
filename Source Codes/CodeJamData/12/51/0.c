#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

int main(){
  int i,j,k,l,m,n;
  int t[2000], p[2000], ind[2000];
  int size, count = 0;

  scanf("%d",&size);
  while(size--){
    printf("Case #%d:",++count);
    scanf("%d",&n);
    rep(i,n) scanf("%d",t+i);
    rep(i,n) scanf("%d",p+i);
    rep(i,n) ind[i] = i;
    rep(i,n) p[i] = 100 - p[i];

    for(;;){
      int fg = 0;

      REP(i,1,n){
        if(t[i-1] * 100 + t[i] * p[i-1] > t[i] * 100 + t[i-1] * p[i]){
          fg = 1;
          k = t[i-1], t[i-1] = t[i], t[i] = k;
          k = p[i-1], p[i-1] = p[i], p[i] = k;
          k = ind[i-1], ind[i-1] = ind[i], ind[i] = k;
        }
      }
      
      if(!fg) break;
    }

    rep(i,n) printf(" %d",ind[i]);
    puts("");
  }

  return 0;
}
