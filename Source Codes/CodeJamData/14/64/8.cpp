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

string problemName = "D";
string smallFileName = problemName + "-small-attempt0";
string largeFileName = problemName + "-large";

//string fileName(1, tolower(problemName[0]));
string fileName = smallFileName;
//string fileName = largeFileName;

string inputFileName = fileName + ".in";
string outputFileName = fileName + ".out";

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
	int n, r;
	cin >> n >> r;
	vector<string> a(n);
	vector<int> b;
	REP (i, n) {
	  cin >> a[i];
	  b.pb(i);
	}
	bool res = false;
	do {
	  int x = b[0];
	  FOR (i, 1, sz(b)) {
	    if (a[x][b[i]] == 'N') x = b[i];
	  }
	  if (x == r) {
	    REP (i, sz (b)) {
	      if (i) cout << ' ';
	      cout << b[i];
	    }
	    cout << endl;
	    res = true;
	    break;
	  }
	} while (next_permutation(all(b)));
	if (!res) {
	  cout << "IMPOSSIBLE" << endl;
	}
    }
    return 0;
}
