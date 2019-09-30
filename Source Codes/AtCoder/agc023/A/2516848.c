#include <stdio.h>
#include <stdlib.h>

int asc(const void *a, const void *b) {
  long long *A = (long long *)a;
  long long *B = (long long *)b;
  if (*A > *B) return 1;
  if (*A < *B) return -1;
  return 0;
}

int main(void) {
  long long i, j;
  long long n;
  long long a;
  long long data;
  long long *sum;
  long long c1, c2;
  long long c_name;
  
  scanf("%lld", &n);
  
  sum = malloc(sizeof(long long) * (n + 1));
  
  data = 0;
  sum[0] = data;
  
  for (i = 1; i < n + 1; i++) {
    scanf("%lld", &a);
    sum[i] = data + a;
    data += a;
  }
  
  qsort(sum, n + 1, sizeof(long long), asc);
  
  c_name = sum[0];
  c1 = 0;
  c2 = 0;
  for (i = 1; i < n + 1; i++) {
    if (c_name == sum[i]) {
      c1++;
      c2 += c1;
    } else {
      c1 = 0;
      c_name = sum[i];
    }
  }
  
  printf("%lld\n", c2);
  
  free(sum);

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:21:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld", &n);
   ^
./Main.c:29:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lld", &a);
     ^