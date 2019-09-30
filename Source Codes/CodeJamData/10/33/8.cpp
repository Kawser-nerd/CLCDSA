#include <iostream>
#include <sstream>
#include <cstring>
#include <cctype>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <algorithm>

#define FOREACH(i, c) for(__typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define REP(i, n) for(int i = 0; i < (n); i++)
#define CLEAR(a) memset(a, 0, sizeof(a))

using namespace std;

struct item {
  int d, r, c;

  item(int dd, int rr, int cc) {
    d = dd;
    r = rr;
    c = cc;
  }
};

int operator<(const item &a, const item &b) {
  if (a.d == b.d)
    if (a.r == b.r)
      return a.c < b.c;
    else
      return a.r < b.r;
  else
    return a.d > b.d;
}

const int maxn = 600;

bool a[maxn][maxn];
int d[maxn][maxn];
bool u[maxn][maxn];
int n, m;

int main() {
  int T;
  cin >> T;
  for (int C = 1; C <= T; C++) {
    cin >> n >> m >> ws;
    REP(r, n)
      for (int c = 0; c < m; c += 4) {
	char ch;
	cin >> ch >> ws;
	int x;
	if (isdigit(ch))
	  x = ch-'0';
	else
	  x = ch-'A'+10;
	a[r][c] = ((x&8) > 0);
	a[r][c+1] = ((x&4) > 0);
	a[r][c+2] = ((x&2) > 0);
	a[r][c+3] = ((x&1) > 0);
      }
    REP(i, m)
      d[n-1][i] = 1;
    REP(i, n)
      d[i][m-1] = 1;
    for (int r = n-2; r >= 0; r--)
      for (int c = m-2; c >= 0; c--) 
	if (a[r][c] == a[r+1][c+1] && a[r][c] != a[r+1][c] && a[r][c] != a[r][c+1]) {
	  int x = min(d[r+1][c], d[r][c+1]);
	  x = min(x, d[r+1][c+1]);
	  d[r][c] = x+1;
	}
	else
	  d[r][c] = 1;
    
    set<item> s;
    REP(r, n)
      REP(c, m)
	s.insert(item(d[r][c], r, c));

    map<int, int> res;
    CLEAR(u);
    while (!s.empty()) {
      item x = *(s).begin();
      s.erase(s.begin());
      if (u[x.r][x.c])
	continue;

      int d = 1;
      bool ok = true;
      while (d < x.d) {
	ok = !u[x.r+d][x.c+d];
	for (int i = 0; ok && i < d; i++)
	  if (u[x.r+d][x.c+i] || u[x.r+i][x.c+d])
	    ok = false;
	if (!ok)
	  break;
	d++;
      }
      if (ok) {
	REP(r, d)
	  REP(c, d)
	    u[x.r+r][x.c+c] = true;
	res[d]++;
      }
      else 
	s.insert(item(d, x.r, x.c));
    }
    cout << "Case #" << C << ": " << res.size() << endl;
    for (map<int, int>::reverse_iterator i = res.rbegin(); i != res.rend(); i++)
      cout << i->first << " " << i->second << endl;
  }
}
