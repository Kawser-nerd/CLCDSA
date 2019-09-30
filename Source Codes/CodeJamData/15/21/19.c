#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define T 1000000

int reverse(int num) {
  int rev = 0;
  while (num > 0) {
    rev *= 10;
    rev += num % 10;
    num /= 10;
  }
  return rev;
}

int main(int agrc, char *argv[]) {
  int *quickest = (int *)malloc(sizeof(int) * (T + 1));
  int *previous = (int *)malloc(sizeof(int) * (T + 1));
  int i;
  for (i = 0;  i <= T; ++i) {
    quickest[i] = 10000000;
    previous[i] = -1;
  }
  quickest[1] = 1;

  int prev, rev;
  for (i = 1; i < T; ++i) {
    if (quickest[i + 1] > quickest[i] + 1) {
      quickest[i + 1] = quickest[i] + 1;
      previous[i + 1] = i;
    }
    if (quickest[reverse(i)] > quickest[i]+ 1) {
      quickest[reverse(i)] = quickest[i] + 1;
      previous[reverse(i)] = i;
      if (reverse(i) < i)
        i = reverse(i) - 1;
    }
  }

  int num_cases;
  scanf("%d", &num_cases);

  int current_case = 1;
  int num;
  while (current_case <= num_cases) {
    scanf("%d", &num);
    printf("Case #%d: %d\n", current_case, quickest[num]);
    i = num;
    /*
    while (i > 0) {
      printf(" %d", i);
      i = previous[i];
    }
    printf("\n");
    */
    ++current_case;
  }

  free(quickest);
  free(previous);

  return EXIT_SUCCESS;
}
