#include <stdint.h>
#include <inttypes.h>
#include <stdio.h>

uint64_t xor(uint64_t n)
{
  return n % 4 == 0 ? n : n ^ xor(n - 1);
}

int main(void)
{
  uint64_t a, b;
  scanf("%" SCNu64 "%" SCNu64, &a, &b);
  printf("%" PRIu64 "\n", xor(a - 1) ^ xor(b));
} ./Main.c: In function ‘main’:
./Main.c:13:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%" SCNu64 "%" SCNu64, &a, &b);
   ^