#include <stdio.h>
#include <stdlib.h>

int main(int agrc, char *argv[]) {
  int test_cases;
  scanf("%d", &test_cases);
  int test_case, samples;
  int *mushrooms;
  int i;
  int estimate_a, estimate_b, diff, max_diff;
  for (test_case = 1; test_case <= test_cases; ++test_case) {
    scanf("%d", &samples);
    mushrooms = (int *)malloc(sizeof(int) * samples);
    for (i = 0; i < samples; ++i)
      scanf("%d", mushrooms + i);
    estimate_a = 0, diff = 0, max_diff = 0;
    for (i = 1; i < samples; ++i) {
      diff = mushrooms[i - 1] - mushrooms[i];
      if (diff > 0) {
        estimate_a += diff;
        max_diff = max_diff > diff ? max_diff : diff;
      }
    }
    estimate_b = 0;
    for (i = 0; i < samples - 1; ++i) {
      estimate_b += max_diff > mushrooms[i] ? mushrooms[i] : max_diff;
    }
    printf("Case #%d: %d %d\n", test_case, estimate_a, estimate_b);
    free(mushrooms);
  }

  return EXIT_SUCCESS;
}
