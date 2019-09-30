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

const int maxn = 203;

int n;
const int M = (int)2e6 + 100;
int add[2 * M], x[2 * M];

void Add( int i, int y )
{
  while (i < 2 * M)
    x[i] += y, i |= i + 1;
}

int Get( int i )
{
  int r = 0;
  while (i >= 0)
    r += x[i], i &= i + 1, i--;
  return r;
}

int Get( int L, int R )
{
  return Get(R) - Get(L);
}

int main()
{
  int tn;
  scanf("%d", &tn);
  for (int tt = 1; tt <= tn; tt++)
  {
    fprintf(stderr, "%d\n", tt);
    scanf("%d", &n);

    memset(add, 0, sizeof(add));
    memset(x, 0, sizeof(x));
    forn(i, n)
    {
      int p, v;
      scanf("%d%d", &p, &v);
      p += M;
      add[p] = v;
    }

    ll cnt = 0;
    forn(i, 2 * M)
      while (add[i])
        if (!Get(i - 1, i))
          Add(i, 1), add[i]--;
        else
        {
          int l = 1, r = i, m;
          while (l < r)
          {
            m = (l + r + 1) / 2;
            if (Get(i - m, i) == m)
              l = m;
            else
              r = m - 1; 
          }
           
          int j = i - l, len = l;
          
          if (add[i] >= len)
          { 
            add[i] -= len, add[i + 1] += len;
            Add(j, 1), Add(i, -1);
            cnt += ((ll)len * (len + 1)) / 2;
          }
          else
          {
            cnt += ((ll)(len + len - add[i] + 1) * add[i]) / 2;
            Add(j, 1), Add(j + add[i], -1);
            add[i + 1] += add[i], add[i] = 0;
          }
        }

    printf("Case #%d: %I64d\n", tt, cnt);
  }
  return 0;
}
