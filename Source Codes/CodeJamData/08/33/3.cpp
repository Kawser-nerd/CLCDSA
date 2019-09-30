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

typedef pair <int, int> pii;
typedef vector <int> vi;
typedef long long int64;
typedef set < int > si;

const int inf = (1 << 30) - 1;
const int64 p = 1000000007;

vector <int64> a, b;
int64 t[1000000];
vector < pair <int64, int> > vt;
int64 tree [2000000];
int list;

void push (int v, int64 w)
{
  v = v + list - 1;
  tree[v] = w;
  while (v > 1)
    {
      v = v >> 1;
      tree[v] = (tree[v*2] + tree[v*2+1]) % p;
    }
}

int64 rmq (int v, int l, int r, int a, int b)
{
  if ((r < a) || (l > b))
    return 0;
  if ((a <= l) && (r <= b))
    return tree[v];
  return (rmq (v * 2, l, (l+r) >> 1, a, b) +
         rmq (v * 2 + 1, ((l + r) >> 1) + 1, r, a, b)) % p;
}

bool lessx (pair <int64, int> p1, pair <int64, int> p2)
{
  if (p1.first != p2.first)
    return p1.first < p2.first;
   else
    return p1.second > p2.second;
}

int main ()
{
  freopen ("inl", "r", stdin);
  freopen ("outl", "w", stdout);
  int nn;
  cin >> nn;
  for (int ii = 1; ii <= nn; ii ++)
    {
      a.clear ();
      b.clear ();
      int n, m;
      int64 x, y, z;
      cin >> n >> m >> x >> y >> z;
      b.resize (m);
      for (int i = 0; i < m; i ++)
        cin >> b[i];
      vt.clear ();
      for (int i = 0; i < n; i ++)
        {
          a.pb (b[i % m]);
          vt.pb (mp (a[i], i+1));
          b[i%m] = (x * b[i%m] + y * (i + 1)) % z;
        }
      memset (t,  0, sizeof (t));
      memset (tree, 0, sizeof (tree));
      sort (all(vt), lessx);
      list = 1;
      while (list < n)
        list *= 2;
      for (int i = 0; i < n; i ++)
        {
          t[vt[i].second] = (1 + rmq (1, 1, list, 1, vt[i].second - 1)) % p;
          push (vt[i].second, t[vt[i].second]);
        }
      int64 ans = 0;
      for (int i = 1; i <= n; i ++)
        ans = (ans + t[i]) % p;
      cout << "Case #" << ii << ": " << ans << endl;

    }
}
