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
string fileName = smallFileName;
//string fileName = largeFileName;

string inputFileName = fileName + ".in";
string outputFileName = fileName + ".out";

char a[1024];
int b[1024];
bool d[16][16][2<<15];

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
	map<int, int> G;
	int m = 0;
	REP (i, n) {
	  cin >> a[i] >> b[i];
	  if (b[i] == 0) {
	    b[i] = -1;
	  } else {
	    if (!G.count(b[i])) {
	      G[b[i]] = m;
	      ++m;
	    }
	    b[i] = G[b[i]];
	  }
	}
	memset(d, 0, sizeof(d));
	REP (i, n+1) {
	  REP (j, 1<<m) {
	    d[0][i][j] = true;
	  } 
	}
	REP (i, n) {
	  REP (j, n+1) {
	    REP (k, 1<<m) if (d[i][j][k]) {
	      if (a[i] == 'E') {
		if (b[i] == -1) {
		  d[i+1][min(j+1, n)][k] = true;
		  REP (t, m) if (!(k & (1<<t))) {
		    d[i+1][j][k^(1<<t)] = true;
		  }
		} else {
		  if (!(k & (1<<b[i]))) {
		    d[i+1][j][k^(1<<b[i])] = true;
		  }
		}
	      } else {
		if (b[i] == -1) {
		  d[i+1][max(j-1, 0)][k] = true;
		  REP (t, m) if ((k & (1<<t))) {
		    d[i+1][j][k^(1<<t)] = true;
		  }
		} else {
		  if ((k & (1<<b[i]))) {
		    d[i+1][j][k^(1<<b[i])] = true;
		  }
		}		
	      }
	    }
	  }
	}
	int res = -1u/4;
	REP (j, n+1) {
	  REP (k, 1<<m) if (d[n][j][k]) {
	    res = min(res, __builtin_popcount(k) + j);
	  }
	}
	if (res == (-1u/4)) {
	  cout << "CRIME TIME" << endl;
	} else {
	  cout << res << endl;
	}
    }
    return 0;
}
