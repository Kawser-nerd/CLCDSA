#include <stdio.h>

#define INF (100000 * 1024)

int P;

int miss(int c)
{
  int result = 0, i;

  for (i = 0; i < P; ++i) {
    if ((c & (1 << i)) == 0) {
      ++result;
    }
  }

  return result;
}

int min(int a, int b)
{
  return a < b ? a : b;
}

int main()
{
  int t, T;
  int M[1024], S[10][1024];
  int i, j, k, c, comun, dif;
  int prev[10][1024];
  int next[10][1024];
  int score, result;
  
  scanf("%d", &T);
  for (t = 1; t <= T; ++t) {
    scanf("%d", &P);
    for (i = 0; i < (1 << P); ++i) {
      scanf("%d", &M[i]);
    }
    for (i = P - 1; i >= 0; --i) {
      for (j = 0; j < (1 << i); ++j)
	scanf("%d", &S[i][j]);
    }

    for (c = 0; c < (1 << P); ++c) {
      score = 0;
      for (i = 0; i < P; ++i) {
	if ((c & (1 << i)) == (1 << i)) {
	  score += S[P - i - 1][0];
	}
      }
      if (miss(c) <= M[0]) {
	prev[P - 1][c] = score;
      } else {
	prev[P - 1][c] = INF;
      }
      //      printf("Config %d: %d\n", c, prev[P - 1][c]);
    }

    for (i = 1; i < (1 << P); ++i) {

      //      printf("i = %d\n", i);

      for (k = P - 2; k >= 0; --k) {
	for (c = 0; c < (1 << (k + 1)); ++c) {
	  prev[k][c] = min(prev[k + 1][(c << 1) | 1], prev[k + 1][c << 1]);
	  //	  printf("prev[%d][%d] = %d\n", k, c, prev[k][c]);
	}
      }
      for (j = 0; j < (1 << P); ++j) {
	next[P - 1][j] = INF;
      }

      comun = 0;
      for (j = P; j >= 0; --j) {
	if ((i & (1 << j)) == ((i - 1) & (1 << j))) {
	  comun++;
	}
      }
      //      printf("comun %d\n", comun);
      dif = P - comun;
      for (c = 0; c < (1 << P); ++c) {
	score = 0;
	for (j = 0; j < dif; ++j) {
	  if ((c & (1 << j)) == (1 << j)) {
	    score += S[P - j - 1][i >> (j + 1)];
	  }
	}
	if (miss(c) <= M[i]) {
	  if (next[P - 1][c] > prev[comun - 1][c >> dif] + score) {
	    next[P - 1][c] = prev[comun - 1][c >> dif] + score;
	  }
	  //	  printf("Config' %d (score %d): %d\n", c, score, next[P - 1][c]);
	}
      }
      for (j = 0; j < 1024; ++j) {
	prev[P - 1][j] = next[P - 1][j];
      }
    }

    result = INF;
    for (i = 0; i < (1 << P); ++i) {
      if (next[P - 1][i] < result) {
	result = next[P - 1][i];
      }
    }

    printf("Case #%d: %d\n", t, result);
  }

  return 0;
}
