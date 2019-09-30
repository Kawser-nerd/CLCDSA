#include <stdio.h>

int main(){
  int n, m, i, j, l;
  int count = 0;
  int aa[30] = {};

  scanf("%d %d", &n, &m);

  for(i = 0; i < n; i++){
    int k; scanf("%d", &k);
    /* printf("k_%d ... %d\n", i, k); */
    for(j = 0; j < k; j++){
      int a; scanf("%d", &a);
      /* printf("a_%d ... %d\n", j, a); */
      a--;
      aa[a]++;
      /* printf("aa[%d] = %d.\n", a, aa[a]); */
    }
  }

  for(l = 0; l < m; l++){
    if(aa[l] == n) count++;
  }

  printf("%d\n", count);

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d", &n, &m);
   ^
./Main.c:11:12: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     int k; scanf("%d", &k);
            ^
./Main.c:14:14: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
       int a; scanf("%d", &a);
              ^