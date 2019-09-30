# include <stdio.h>

int main(){
  int n, k;
  int ans = 1;
  scanf("%d %d", &n, &k);
  for (int i = 0; i < n; i++){
    ans += (ans < k)*ans + (ans >= k)*k;
  }
  printf("%d\n",ans);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d", &n, &k);
   ^