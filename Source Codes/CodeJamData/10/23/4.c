#include <stdio.h>
#include <assert.h>

#define MODULO 100003

#define MAX 505

int comb[MAX][MAX];
int s[MAX][MAX];

int main()
{
  int i, j, n, rank, pos, t, T, sum;

  for (i = 0; i < MAX; ++i) {
    comb[0][i] = 0;
    comb[i][0] = 1;
  }
  for (i = 1; i < MAX; ++i) {
    for (j = 1; j < MAX; ++j) {
      comb[i][j] = (comb[i - 1][j] + comb[i - 1][j - 1]) % MODULO;
    }
  }

  for (i = 0; i < MAX; ++i) {
    for (j = 0; j < MAX; ++j) {
      s[i][j] = 0;
    }
  }
  for (n = 2; n <= 500; ++n) {
    s[n][1] = 1;
  }
  for (n = 3; n <= 500; ++n) {
    for (rank = n - 1; rank >= 2; --rank) {
      for (pos = rank - 1; ((pos >= 1) && (rank - pos <= n - rank)); --pos) {
	assert(0 <= n - rank + 1);
	assert(n - rank + 1 < MAX);
	assert(0 <= rank - pos - 1);
	assert(rank - pos - 1 < MAX);
	long long a = comb[n - rank - 1][rank - pos - 1];
	long long b = s[rank][pos];
	long long r = (a * b) % MODULO;
	s[n][rank] += r;
	s[n][rank] %= MODULO;
      }
    }
  }

/*   printf("blabla %d %d %d\n", s[4][3], s[4][2], s[4][1]); */


/*   long long aa = 100078; */
/*   long long bb = 100089; */
/*   long long rr = (aa * bb) % MODULO; */

/*   int rrr = rr; */
/*   printf("bleah %d\n", rrr); */


  scanf("%d", &T);
  for (t = 1; t <= T; ++t) {
    scanf("%d", &n);
    sum = 0;
    for (i = 1; i <= n - 1; ++i) {
      sum += s[n][i];
      sum %= MODULO;
    }
    printf("Case #%d: %d\n", t, sum);
  }

  return 0;
}
