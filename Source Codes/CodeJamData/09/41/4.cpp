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

const int maxn = 43;

int n, k[maxn];
char a[maxn][maxn];

int main()
{
  int tn;
  scanf("%d", &tn);
  for (int tt = 1; tt <= tn; tt++)
  {
    scanf("%d", &n);
    forn(i, n)
      scanf("%s", a[i]);
    forn(i, n)
    {
      k[i] = n - 1;
      while (k[i] >= 0 && a[i][k[i]] == '0')
        k[i]--;
    }

    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
      int j = i;
//      printf("i=%d j=%d\n", i, j);
      while (k[j] > i)
        j++;
//      printf("i=%d j=%d\n", i, j);
      for (int t = j - 1; t >= i; t--)
      {
        swap(k[t], k[t + 1]);
        cnt++;
      }
    }
    printf("Case #%d: %d\n", tt, cnt);
  }
  return 0;
}
