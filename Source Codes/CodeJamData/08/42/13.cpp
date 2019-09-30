#include <cstdio>
  #include <cstring>
  #include <cmath>
  #include <algorithm>

  using namespace std;

  #define sqr(x) ((x) * (x))

  const int maxLen = 500 + 5;

  char a[2][maxLen];
  int st[2][maxLen], en[2][maxLen];
  int len[2], Tot[2];
  int f[maxLen][maxLen];
  bool SAME[maxLen][maxLen];

  bool legal(char c)
    {
       if (c >= 'a' && c <= 'z') return 1;
       if (c >= 'A' && c <= 'Z') return 1;
       if (c >= '0' && c <= '9') return 1;
       return 0;
    }

  void init()
    {
       for (int k = 0; k < 2; k ++)
         {
            len[k] = 0;
            while (1)
              {
                 a[k][len[k]] = getchar();
                 if (a[k][len[k]] == '\r') continue;
                 if (a[k][len[k]] == '\n' || a[k][len[k]] == EOF) break;
                 ++ len[k];
                 if (a[k][len[k]] & 128) a[k][len[k] ++] = getchar();
              }

            /*scanf("%s", &a[k]);
            len[k] = strlen(a[k]);*/

            Tot[k] = 0;
            int pos = 0;
            while (pos < len[k])
              {
                 if (a[k][pos] < 0)
                   {
                      st[k][++Tot[k]] = pos;
                      en[k][Tot[k]] = pos + 1;
                      pos += 2;
                      continue;
                   }
                 if (!legal(a[k][pos])) 
                   {
                      st[k][++Tot[k]] = pos;
                      en[k][Tot[k]] = pos;
                      pos ++;
                      continue;
                   }
                 st[k][++Tot[k]] = pos;
                 while (1)
                   {
                      if (pos + 1 == len[k] || !legal(a[k][pos + 1])) break;
                      ++ pos;
                   }
                 en[k][Tot[k]] = pos;
                 ++ pos;
              }
         }
    }

  bool same(int l, int r, int L, int R)
    {
       if (r - l != R - L) return 0;
       while (l <= r)
         {
           if (a[0][l] != a[1][L]) return 0;
           ++l, ++L;
         }
       return 1;
    }

  void work()
    {
       memset(f, 0, sizeof(f));

       for (int i = 1; i <= Tot[0]; i ++)
         for (int j = 1; j <= Tot[1]; j ++)
           SAME[i][j] = same(st[0][i], en[0][i], st[1][j], en[1][j]);

       for (int i = 1; i <= Tot[0]; i ++)
         for (int j = 1; j <= Tot[1]; j ++)
           {
              f[i][j] = f[i - 1][j];
              f[i][j] >?= f[i][j - 1];
              int s_i = i, s_j = j;
              while (s_i && s_j)
                {
                   if (!SAME[s_i][s_j]) break;
                   f[i][j] >?= f[s_i - 1][s_j - 1] + sqr(i - s_i + 1);
                   --s_i, --s_j;
                }
           }
       printf("%d\n", f[Tot[0]][Tot[1]]);
    }

  int main()
    {
       freopen("p2.in", "r", stdin);
         init();
         work();
       return 0;
    }