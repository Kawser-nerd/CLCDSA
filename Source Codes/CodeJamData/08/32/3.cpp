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

string s;
vector <int64> a;
int64 t[300][3][50];

bool check (int64 s)
{
  return ((s % 2 == 0) || (s % 3 == 0) || (s % 5 == 0) || (s % 7 == 0));
}

int64 go (int64 s, int64 op, int v)
{
  if (v == a.size ())
    return (int) check (s);
   else
  if (t[s][op+1][v] != -1)
    return t[s][op+1][v];
   else
    {
      int64 res = 0;
      int64 s1 = 0;
      for (int i = v; i < a.size(); i ++)
        {
          s1 = (s1 * 10 + a[i]) % 210;
          res += go ((s + s1 * op + 210) % 210, 1, i+1);
          if (i + 1 != a.size ()) 
            res += go ((s + s1 * op + 210) % 210, -1, i+1);
        }
      return t[s][op+1][v] = res;
    }
}

int main ()
{
  freopen ("inl", "r", stdin);
  freopen ("outl", "w", stdout);
  int nn;
  cin >> nn;
  for (int ii = 1; ii <= nn; ii ++)
    {
      cin >> s;
      a.clear ();
      for (int i = 0; i < s.length(); i ++)
        a.pb (s[i] - '0');
      memset (t, 255, sizeof (t));
      go (0, 1, 0);
      cout << "Case #" << ii << ": " << t[0][2][0] << endl;
    }
}
