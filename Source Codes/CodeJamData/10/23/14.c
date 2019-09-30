#include <stdio.h>

int dp_valid[501][501];
int dp [501][501]; // dp[x][y] := # of x elements subset of {2, ..., y} that is pure
int c_valid [501][501];
int c [501][501]; // c[x][y] := x choose y

int choose(int n, int k)
{
  if (c_valid [n][k])
    return c [n][k];
  else if (k == n || k == 0)
    return c_valid [n][k] = 1, c [n][k] = 1;
  else
    return c_valid [n][k] = 1, c [n][k] = (choose (n - 1, k) + choose (n - 1, k - 1)) % 100003;
}

int bar (int n, int N)
{
  if (dp_valid [n][N])
    return dp [n][N];
  else if (n == 1)
    return dp_valid [n][N] = 1, dp [n][N] = 1;
  else if (n == N - 1)
    return dp_valid [n][N] = 1, dp [n][N] = 1;
  else
    {
      int i;

      for (i = 1; i < n; i++)
	{
	  if (N - n - 1 >= n - i - 1)
	    dp [n][N] = (dp [n][N] + bar(i, n) * choose(N - n - 1, n - i - 1)) % 100003;
	}

      return dp_valid [n][N] = 1, dp [n][N];
    }
}

int foo (int N)
{
  int i;
  int sum = 0;

  for (i = 1; i < N; i++)
    sum = (sum + bar(i, N)) % 100003;

  return sum;
}

int main()
{
  int T;

  int t;

  scanf ("%d", &T);

  for (t = 1; t <= T; t++)
    {
      int N;

      scanf ("%d", &N);

      printf ("Case #%d: %d\r\n", t, foo(N));
    }

  return 1;
}
