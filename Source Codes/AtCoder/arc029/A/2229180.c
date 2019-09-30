#include <stdio.h>
#include <stdlib.h>

#define BUF_SIZE 0x10

#define min(a, b) (a < b ? a : b)
#define max(a, b) (a > b ? a : b)

int is_small(const void* a, const void* b)
{
  return *(int*)a < *(int*)b;
}

void sort(int* array, size_t size)
{
  qsort(array, size, sizeof(int), is_small);
}

int main()
{
  int n;
  scanf("%d", &n);
  int meat[BUF_SIZE];
  for(int i = 0; i < n; i++) {
    scanf("%d", &meat[i]);
  }
  sort(meat, n);
  int oven1 = 0;
  int oven2 = 0;
  int cnt = 0;
  for(int i = 0; i < n; i++) {
    if(oven1 == 0) {
      oven1 = meat[i];
    } else if(oven2 == 0) {
      oven2 = meat[i];
    } else {
      fputs("error: oven is full\n", stderr);
      exit(1);
    }
    int time_passed = min(oven1, oven2);
    oven1 = oven1 - time_passed;
    oven2 = oven2 - time_passed;
    cnt += time_passed;
  }
  // oven1 xor oven2 must be 0
  cnt += oven1 + oven2;
  printf("%d\n", cnt);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:22:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &n);
   ^
./Main.c:25:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &meat[i]);
     ^