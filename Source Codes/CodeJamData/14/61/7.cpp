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

string problemName = "A";
string smallFileName = problemName + "-small-attempt0";
string largeFileName = problemName + "-large";

//string fileName(1, tolower(problemName[0]));
//string fileName = smallFileName;
string fileName = largeFileName;

string inputFileName = fileName + ".in";
string outputFileName = fileName + ".out";

int a[2048][2048];
int d[2][2];

int solve(vector<int> v) {
  memset(d, 0, sizeof(d));
  int g = 0;
  REP (i, sz (v)) {
    g += v[i];
    d[i % 2][v[i]]++;
  }
  if (g != sz(v)/2) return -1;
  return min(d[0][0], d[0][1]);
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
	int n;
	cin >> n;
	n*=2;
	REP (i, n) {
	  string s;
	  cin >> s;
	  REP (j, n) {
	    a[i][j] = s[j]-'0';
	  }
	}
	bool res = true;
	int resnum = -1;
	vector<int> g1, g2;
	REP (i, n) {
	  bool q = false, w = false;
	  REP (j, n) {
	    if (a[i][j] == a[0][j]) {
	      q = true;
	    } else {
	      w = true;
	    }
	  }
	  if (q && w) {
	    res = false;
	    break;
	  }
	  if (q) g1.pb(0); else g1.pb(1);
	}
	REP (i, n) {
	  bool q = false, w = false;
	  REP (j, n) {
	    if (a[j][i] == a[j][0]) {
	      q = true;
	    } else {
	      w = true;
	    }
	  }
	  if (q && w) {
	    res = false;
	    break;
	  }
	  if (q) g2.pb(0); else g2.pb(1);
	}
	// cout << endl;
	// REP (i, sz (g1)) cout << g1[i] << ' '; cout << endl;
	// REP (i, sz (g1)) cout << g2[i] << ' '; cout << endl;
	// cout << endl;
	cout << "Case #" << (test + 1) << ": ";
	if (res) {
	  int x1 = solve(g1);
	  int x2 = solve(g2);
	  if (x1 == -1 || x2 == -1) res = false; else {
	    resnum = x1+x2;
	  }
	}
	if (!res) {
	  cout << "IMPOSSIBLE\n"; 
	} else {
	  cout << resnum << endl;
	}
    }
    return 0;
}
