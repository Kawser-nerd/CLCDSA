#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <set>
#include <map>

using namespace std;

#define pb push_back
#define all(x) x.begin(), x.end()
#define mp make_pair

const int inf = (1 << 30) - 1;

typedef pair <int, int> pii;
typedef vector <int> vi;
typedef long long int64;
typedef set < int > si;

vector <int64> a, alf;

int main ()
{
  int nn;
  cin >> nn;
  for (int ii = 1; ii <= nn; ii ++)
    {
      int64 p, k, l;
      cin >> p >> k >> l;
      a.clear ();
      alf.clear ();
      a.resize (l);
      alf.resize (100000);
      for (int i = 0; i < l; i ++)
        cin >> a[i];
      sort (all(a));
      int64 ans = 0;
      int h, t;
      h = 0;
      t = k - 1;
      for (int i = 0; i <= t; i ++)
        alf[i] = 1;
      for (int i = l - 1; i >= 0; i --)
        {
          ans += a[i] * alf[h];
          t ++;
          if (t >= 100000)
            cerr << "qweqe";
          alf[t] = alf[h] + 1;
          h ++;
        }
      cout << "Case #" << ii << ": " << ans << endl;
    }
}
