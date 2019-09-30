#include <stdio.h>
#include <inttypes.h>
#include <stdbool.h>

bool seen_all(bool *seen) {
  bool yes = true;
  for (int i = 0; i < 10; i++)
    if (seen[i] == false)
      yes = false;
  return yes;
}

void real_test_case(uint64_t N) {
  uint64_t cur = 0;
  bool seen[10] = { 0 };
  do {
    cur += N;
    uint64_t copy = cur;
    while (copy != 0) {
      seen[copy % 10] = true;
      copy /= 10;
    }
  } while (!seen_all(seen));
  printf("%" PRIu64, cur);
}

void test_case(uint64_t N) {
  if (N == 0) {
    printf("INSOMNIA");
  } else {
    real_test_case(N);
  }
}

int main(int argc, char *argv[]) {
  int T;
  scanf("%d", &T);

  for (int i = 1; i <= T; i++) {
    uint64_t N;
    scanf("%" SCNu64, &N);
    printf("Case #%d: ", i);
    test_case(N);
    printf("\n");
  }

  return 0;
}
