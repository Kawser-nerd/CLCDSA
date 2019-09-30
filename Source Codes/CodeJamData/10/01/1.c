#include <stdio.h>

int main() {
  int cases,n,k,caseno=1,v;
  scanf("%d",&cases);
  while(cases--) {
    scanf("%d %d",&n,&k);
    v=(1<<n)-1;
    printf("Case #%d: %s\n",caseno++,
      (k&v)==v?"ON":"OFF");
  }
  return 0;
}
