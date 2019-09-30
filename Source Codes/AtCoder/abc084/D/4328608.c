#include <stdio.h>
#include <math.h>

#define NUM 100000

int prime[NUM + 1];
int counts[NUM + 1];

void init_prime() {
  int i, j;
  int sq_num = (int)sqrt((double)NUM);

  for (i = 0; i < NUM; i++) {
    prime[i] = i % 2;
  }
  prime[0] = prime[1] = 0;
  prime[2] = 1;

  for (i = 3; i < sq_num; i++) {
    if (prime[i] == 0) {
      continue;
    }
    for (j = i; i * j <= NUM; j += 2) {
      prime[i * j] = 0;
    }
  }
}

void init_counts() {
  int i;

  counts[0] = counts[1] = 0;
  for (i = 2; i <= NUM; i++) {
    counts[i] = counts[i - 1];
    if (prime[i] && prime[(i + 1) / 2]) {
      counts[i]++;
    }
  }
}

void solv(int q) {
  int i, l, r;

  for (i = 0; i < q; i++) {
    scanf("%d %d", &l, &r);
    printf("%d\n", counts[r] - counts[l - 1]);
  }
}

int main(int argc, char **argv) {
  int q;

  init_prime();
  init_counts();
  while (scanf("%d", &q) != EOF) {
    solv(q);
  }

  return 0;
} ./Main.c: In function ‘solv’:
./Main.c:45:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d", &l, &r);
     ^