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

int a[1234567];

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
	long long p, q, r, s;
	cin >> n >> p >> q >> r >> s;
	long long S = 0;
	REP (i, n) {
	  a[i] = (((long long) i * p + q) % r + s);
	  S += a[i];
	}
	long long A = 0, B = 0;
	int i = 0;
	long double f = 0;
	REP (j, n) {
	  B += a[j];
	  while (i < j && A + a[i] <= B - a[i]) {
	    A += a[i];
	    B -= a[i];
	    ++i;
	  }
	  f = max (f, 1 - ((long double) max(max(A, B), S-A-B) / S));
	  f = max (f, 1 - ((long double) max(max(A+a[i], B-a[i]), S-A-B) / S));
	}
	printf("%.12Lf\n", f);
    }
    return 0;
}
