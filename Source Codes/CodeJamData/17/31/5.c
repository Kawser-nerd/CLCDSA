#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef struct {
  double h, r;
} cyl_t;

int num_bits(int n){
  int result;

  result = 0;
  while (n){
    n &= n - 1;
    ++result;
  }
  
  return result;
}

double stack_area(cyl_t* all, int N, int which){
  int i;
  double result, max_r;

  max_r = 0;
  result = 0;
  for (i = 0; i < N; ++i){
    if (which & (1 << i)){
      result += all[i].h * all[i].r * 2;
      max_r = (all[i].r > max_r) ? all[i].r : max_r;
    }
  }
  result += max_r * max_r;

  result *= M_PI;

  return result;
}

int main(int argc, char** argv[]){
  int T, N, K, t, i;
  cyl_t* all;
  double this, max;

  scanf("%d", &T);

  for (t = 1; t <= T; ++t){
    max = 0;
    printf("Case #%d: ", t);

    scanf(" %d %d", &N, &K);
    all = malloc(N * sizeof(cyl_t));
    for (i = 0; i < N; ++i){
      scanf(" %lf %lf", &(all[i].r), &(all[i].h));
    }

    for (i = 0; i < (1 << N); ++i){
      if (num_bits(i) == K){
        this = stack_area(all, N, i);
        max = this > max ? this : max;
      }
    }

    printf("%lf", max);
    free(all);
    printf("\n");
  }

  return 0;
}
