#include <stdio.h>

int main() {
  int roundtrip, number_of_bucket;
  scanf("%d", &number_of_bucket);
  roundtrip = (number_of_bucket % 2 == 0)? number_of_bucket/2 : number_of_bucket/2 + 1;
  printf("%d\n", roundtrip);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &number_of_bucket);
   ^