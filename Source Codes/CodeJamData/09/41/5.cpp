#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <set>
#include <sstream>
#include <cassert>
#include <ctime>
#include <cstdlib>
#include <cstring>
#include <cmath>

#define eps 1e-9

#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define sz(v)((v).size())

#define fi first
#define se second
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef unsigned long long ull;
typedef double dbl;
typedef long double ldbl;

using namespace std;

int a[110], b[110];

bool ok( int * a, int n)
{
  sort(a, a + n);
  for (int i = 0; i < n; i++)
    if (a[i] > i)
      return false;
  return true;
}

int main( void )
{
  int tn;
  scanf("%d", &tn);

  for (int tt = 1; tt <= tn; tt++)
  {
    printf("Case #%d: ", tt);

    int n;
    scanf("%d", &n);
    string s;
    for (int i = 0; i < n; i++)
    {
      cin >> s;
      int t = n - 1;
      while (t && s[t] == '0') t--;
      a[i] = t;
    }

    int res = 0;
    for (int i = n - 1; i >= 0; i--)
    {
      for (int j = i; j >= 0; j--)
      {
        for (int k = j; k < i; k++)
          b[k] = a[k + 1];
        for (int k = 0; k < j; k++)
          b[k] = a[k];
        if (ok(b, i))
        {
          res += (i - j);
          for (int k = j; k < i; k++)
            a[k] = a[k + 1];
          break;
        }
      }
    }


    printf("%d\n", res);
  }

   
  
  return 0;
}