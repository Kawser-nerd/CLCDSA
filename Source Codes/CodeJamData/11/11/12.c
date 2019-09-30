#include <stdio.h>
typedef long long ll;
int main() {
  ll n,pd,pg;
  int cases,caseno=1,i;
  scanf("%d",&cases);
  while(cases--) {
    scanf("%I64d %I64d %I64d",&n,&pd,&pg);
    printf("Case #%d: ",caseno++);
    for(i=1;i<=n && i<1000;i++) {
      if(i*pd%100==0) {
        if(pd==100 && pg==100) goto ok;
        if(pd==0 && pg==0) goto ok;
        if(pg>0 && pg<100) goto ok;
      }
    }
    puts("Broken");
    continue;
  ok:
    puts("Possible");
  }
  return 0;
}
