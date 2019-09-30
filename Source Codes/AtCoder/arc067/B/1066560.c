#include <stdio.h>

#define MIN(x,y) ((x)<(y)?(x):(y))

typedef long long int ll;

int x[100000];

int main(){
  int i, n, a, b;
  ll ans;
  scanf("%d%d%d", &n, &a, &b);
  for(i=0;i<n;i++) scanf("%d", x+i);
  ans=0;
  for(i=1;i<n;i++){
    ans += MIN((ll) a*(x[i]-x[i-1]), b);
  }
  printf("%lld\n", ans);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:12:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d", &n, &a, &b);
   ^
./Main.c:13:20: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i=0;i<n;i++) scanf("%d", x+i);
                    ^