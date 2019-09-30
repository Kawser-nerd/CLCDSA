const int maxp = 100000;
#include <pe>

char mat[105][105];
int  can[105][105];

int solve(int r, int c)
{
  int have[128] = {0};
  for (int i = 0; i < r; ++i)
    for (int j = 0; j < c; ++j)
      can[i][j] = 15;
  for (int i = 0; i < r; ++i)
    for (int j = 0; j < c; ++j)
      if (have[j] == 0)
        if (mat[i][j] != '.')
        {
          can[i][j] ^= 1;
          have[j] = 1;
        }
  memset(have, 0, sizeof have);
  for (int i = r-1; i >= 0; --i)
    for (int j = 0; j < c; ++j)
      if (have[j] == 0)
        if (mat[i][j] != '.')
        {
          can[i][j] ^= 2;
          have[j] = 1;
        }
  memset(have, 0, sizeof have);
  for (int j = 0; j < c; ++j)
    for (int i = 0; i < r; ++i)
      if (have[i] == 0)
        if (mat[i][j] != '.')
        {
          can[i][j] ^= 4;
          have[i] = 1;
        }
  memset(have, 0, sizeof have);
  for (int j = c-1; j >= 0; --j)
    for (int i = 0; i < r; ++i)
      if (have[i] == 0)
        if (mat[i][j] != '.')
        {
          can[i][j] ^= 8;
          have[i] = 1;
        }
  int ans = 0;
  for (int i = 0; i < r; ++i)
    for (int j = 0; j < c; ++j)
      if (mat[i][j] != '.')
      {
        if (can[i][j] == 0) return -1;
        int f = 0;
        if (mat[i][j] == '^') f = 1;
        if (mat[i][j] == 'v') f = 2;
        if (mat[i][j] == '<') f = 4;
        if (mat[i][j] == '>') f = 8;
        if (f & can[i][j]) ; else ++ans;
      }
  return ans;
}
int main()
{
  init_primes();
  const int T = Rint();
  for (int id = 1; id <= T; ++id)
  {
    int R = Rint(), C = Rint();
    for (int i = 0; i < R; ++i)
      scanf("%s", mat[i]);
    int ans = solve(R, C);
    if (ans == -1) printf("Case #%d: IMPOSSIBLE\n", id);
    else printf("Case #%d: %d\n", id, ans);
  }
  return 0;
}