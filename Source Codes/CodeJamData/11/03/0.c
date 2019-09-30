#include <stdio.h>

int a[1024],n;

int main() {
  int cases,caseno=1,i,v,sum;
  int best;
  scanf("%d",&cases);
  while(cases--) {
    scanf("%d",&n);
    for(i=0;i<n;i++) scanf("%d",&a[i]);
    for(sum=v=i=0;i<n;i++) v^=a[i],sum+=a[i];
    if(v) {
      printf("Case #%d: NO\n",caseno++);
      continue;
    }
    best=123123123;
    for(i=0;i<n;i++) if(best>a[i]) best=a[i];
    best=sum-best;
    if(best<0) printf("Case #%d: NO\n",caseno++);
    else printf("Case #%d: %d\n",caseno++,best);
  }
  return 0;
}
