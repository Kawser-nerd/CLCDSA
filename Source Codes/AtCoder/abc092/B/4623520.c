#include <stdio.h>

int main(){
  int n,d,x;
  scanf("%d%d%d", &n, &d, &x);
  int a[n];
  int i;
  for(i=0;i<n;i++){
    scanf("%d", &a[i]);
  }
  int ans = x;
  for(i=0;i<n;i++){
    ans += (d-1)/a[i] + 1;
  }
  printf("%d\n", ans);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d", &n, &d, &x);
   ^
./Main.c:9:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &a[i]);
     ^