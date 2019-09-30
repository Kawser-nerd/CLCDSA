#include <stdio.h>
#include <limits.h>

int main(void) 
{
  int n, m, k, i, j, b, ans;
  scanf("%d %d", &n, &m);
  unsigned int list = UINT_MAX, a;
  for(i = 0; i < n; ++i) {
    scanf("%d", &k); a = 0u;
    for(j = 0; j < k; ++j){
      scanf("%d", &b); a |= 1u << b;
    }
    //printf("a = %d, ", a);
    list &= a;
    //printf("%d\n", list);
  }
  
  ans = 0;
  for(i = 0; i < 31; ++i) {
    //printf(" check: %d result: %d\n", 1u << i, list & (1u<<i) );
    if( (list & (1u << i)) != 0) { ++ans; }
  }
  printf("%d\n", ans);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d", &n, &m);
   ^
./Main.c:10:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &k); a = 0u;
     ^
./Main.c:12:7: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
       scanf("%d", &b); a |= 1u << b;
       ^