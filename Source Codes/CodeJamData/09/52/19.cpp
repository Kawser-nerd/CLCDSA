#include <cmath>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>

#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <functional>
#include <map>
#include <set>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define forit(i, a) for (__typeof((a).begin()) i = (a).begin(); i != (a).end(); i++)
#define sz(a) (int)(a).size()
#define all(a) (a).begin(), (a).end()
#define zero(a) memset(a, 0, sizeof(a))
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef vector <int> vi;
typedef pair <int, int> pii;

const int maxn = 100;
const int mlen = 999;

int K, n, k, cnt[maxn][26];
int an = 0, alen[5], a[5][4];
char s[mlen];

const int MOD = 10009;

int ans = 0;
int sum[26];

void dfs( int i )
{
  if (i == K)
  {
    forn(j, an)
    {
      int r = 1;
      forn(t, alen[j])
        r = (r * sum[a[j][t]]) % MOD;
      ans = (ans + r) % MOD;
    }
    return;
  }

  forn(j, n)
  {
    forn(t, 26)
      sum[t] += cnt[j][t];
    dfs(i + 1);
    forn(t, 26)
      sum[t] -= cnt[j][t];
  }
}

int main()
{
  int tn;
  scanf("%d", &tn);
  for (int tt = 1; tt <= tn; tt++)
  {
    fprintf(stderr, "%d\n", tt);
    scanf("%s%d%d", s, &k, &n);

    int pos = 0;
    an = 0;
    while (s[pos])
    {
      if (s[pos] == '+')
        pos++;
      alen[an] = 0;
      while (isalpha(s[pos]))
      {
        a[an][alen[an]++] = s[pos] - 'a';
        pos++;
      }
      an++;
    }

    memset(cnt, 0, sizeof(cnt));
    forn(i, n)
    {
      scanf("%s", s);
      for (int j = 0; s[j]; j++)
        cnt[i][s[j] - 'a']++;
    }

    printf("Case #%d:", tt);
    for (K = 1; K <= k; K++)
    {
      ans = 0;
      memset(sum, 0, sizeof(sum));
      dfs(0);
      printf(" %d", ans % MOD);
    }
    puts("");
  }
  return 0;
}
