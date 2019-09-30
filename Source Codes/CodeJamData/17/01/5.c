/* Uses C99 standard, compile accordingly.
   Considering gcc, something like this should do:

   gcc -std=c99 solution.c -o solution
*/
#include <stdio.h>
#include <string.h>

#define MAX_PANCAKES 1023


void
flip(char *S, int K, int i) {
  for (int j = i; j < i+K; j++) {
    if (S[j] == '+') {
      S[j] = '-';
    } else if (S[j] == '-') {
      S[j] = '+';
    }
  }
}

int
solve(char *S, int K) {
  int flips = 0;
  int length = strlen(S);

  for (int i = 0; i < length; i++) {
    if (S[i] == '-') {
      if (i + K > length) {
        return -1;
      }

      flip(S, K, i);
      flips++;
    }
  }

  return flips;
}

int
main(int argc, char **argv) {
  int T;
  scanf("%d", &T);

  for (int c = 1; c <= T; c++) {
    char S[MAX_PANCAKES];
    int K;
    scanf("%s %d", S, &K);

    int solution = solve(S, K);
    if (solution < 0) {
      printf("Case #%d: IMPOSSIBLE\n", c);
    } else {
      printf("Case #%d: %d\n", c, solution);
    }
  }

  return 0;
}
