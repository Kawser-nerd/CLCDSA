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

string problemName = "B";
string smallFileName = problemName + "-small-attempt0";
string largeFileName = problemName + "-large";

//string fileName(1, tolower(problemName[0]));
//string fileName = smallFileName;
string fileName = largeFileName;

string inputFileName = fileName + ".in";
string outputFileName = fileName + ".out";

int h[128], g[128];
int a[128][11][11*100 + 1];

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
	int p, q, n;
	cin >> p >> q >> n;
	REP (i, n) {
	  cin >> h[i] >> g[i];
	}
	memset(a, -1, sizeof(a));
	a[0][0][1] = 0;
	REP (i, n) {
	  REP (j, 11) {
	    REP (k, 11 * n + 1) if (a[i][j][k] != -1) {
	      if (j * q + k * p >= h[i]) {
		int & v = a[i+1][0][k - ((h[i] - j*q) + p - 1) / p];
		v = max(v, a[i][j][k] + g[i]);
	      }
	      if ((j + 1) * q >= h[i]) {
		int & v = a[i+1][0][k+1];
		v = max(v, a[i][j][k]);
	      } else {
		int & v = a[i][j+1][k+1];
		v = max(v, a[i][j][k]);
	      }
	    }
	  }
	}
	int res = 0;
	REP (k, 11 * n + 1) res = max(res, a[n][0][k]);
	cout << res << endl;
    }
    return 0;
}
