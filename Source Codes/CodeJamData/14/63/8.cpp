#include <cstring>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
#define all(a) (a).begin(),(a).end()
#define UN(a) sort(all(a)),(a).resize(unique(all(a))-(a).begin())
#define sz(a) ((int) (a).size())
#define pb push_back
#define CL(a,b) memset ((a), (b), sizeof (a))
#define X first
#define Y second

typedef vector<int> vi;

typedef pair<int, int> pii;
typedef long long ll;

string problemName = "C";
string smallFileName = problemName + "-small-attempt0";
string largeFileName = problemName + "-large";

//string fileName(1, tolower(problemName[0]));
//string fileName = smallFileName;
string fileName = largeFileName;

string inputFileName = fileName + ".in";
string outputFileName = fileName + ".out";

void out(vector<int> x) {
  REP (i, sz (x)) {
    cout << x[i] << ' ';
  }
  cout << endl;
}

int main () {
    freopen(inputFileName.data(), "r", stdin);
    if (fileName == smallFileName || fileName == largeFileName)
    {
	freopen(outputFileName.data(), "w", stdout);
    }
    int T;
    cin >> T;
    REP (test, T) {
	cout << "Case #" << (test + 1) << ": ";
	int n;
	cin >> n;
	vector<int> a(n);
	REP (i, n) {
	  string s;
	  cin >> s;
	  a[i] = s[0]-'A';
	}
	vector<vector<int> > b(n);
	vector<int> deg(n);
	REP (i, n-1) {
	  int q, w;
	  cin >> q >> w;
	  --q, --w;
	  b[q].pb(w);
	  b[w].pb(q);
	  deg[q]++;
	  deg[w]++;
	}
	vector<int> next;
	REP (i, n) if (deg[i] == 1) {
	  next.pb(i);
	}
	vector<int> eq(n);
	int totaleq = 0;
	vector<int> last;
	while (sz(next)) {
	  vector<pair<pair<int, vector<int> >, int> > st;
	  REP (i, sz (next)) {
	    int x = next[i];
	    vi ch;
	    REP (j, sz (b[x])) {
	      int y = b[x][j];
	      if (deg[y] != -1) continue;
	      ch.pb(eq[y]);
	    }
	    sort(all(ch));
	    st.pb(make_pair(make_pair(a[x], ch), x));
	  }
	  sort(all(st));

	  REP (i, sz (st)) {
	    int x = st[i].Y;
	    if (!i || st[i].first != st[i-1].first) {
	      eq[x] = totaleq;
	      totaleq++;
	    } else {
	      eq[x] = eq[st[i-1].Y];
	    }
	    deg[x] = -1;
	  }
	  last = next;
	  next.clear();
	  REP (i, sz (st)) {
	    int x = st[i].Y;
	    REP (j, sz (b[x])) {
	      int y = b[x][j];
	      if (deg[y] == -1) continue;
	      deg[y]--;
	      if (deg[y] == 1) {
		next.pb(y);
	      }
	    }
	  }
	}
	bool res = false;
	if (sz(last) == 2 && (eq[last[0]] == eq[last[1]])) {
	  res = true;
 	} else {
	  vector<bool> bad(n);
	  REP (i, sz (last)) {
	    bad[last[i]] = true;
	  }
	  for (int i = 0; i < sz(last); ++i) {
	    int x = last[i];
	    map<int, pii> f;
	    
	    REP (j, sz (b[x])) {
	      int y = b[x][j];
	      if (bad[y]) continue;
	      f[eq[y]].X++;
	      f[eq[y]].Y = y;
	    }
	    for (map<int, pii>::iterator it = f.begin(); it != f.end(); ++it) {
	      if (it->Y.X & 1) {
		last.pb(it->Y.Y);
		bad[last.back()] = true;
	      }
	    }
	  }
	  res = true;
	  REP (i, sz (last)) {
	    int x = last[i];
	    int cc = 0;
	    REP (j, sz(b[x])) {
	      int y = b[x][j];
	      if (bad[y]) {
		++cc;
	      }
	    }
	    if (cc >= 3) {
	      res = false;
	      break;
	    }
	  }
	}
	if (res) {
	  cout << "SYMMETRIC" << endl;
	} else {
	  cout << "NOT SYMMETRIC" << endl;
	}
    }
    return 0;
}
