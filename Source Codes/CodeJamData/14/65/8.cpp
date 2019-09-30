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

string problemName = "E";
string smallFileName = problemName + "-small-attempt1";
string largeFileName = problemName + "-large";

//string fileName(1, tolower(problemName[0]));
string fileName = smallFileName;
//string fileName = largeFileName;

string inputFileName = fileName + ".in";
string outputFileName = fileName + ".out";

long long res[1000000];

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
	ll n, a, b;
	cin >> n >> a >> b;
		memset(res,0 , sizeof(res));
	FOR (i, 0, a) res[i] = 1;
	for (int i = a; res[i-1] < n; ++i)
	  res[i] = res[i-a] + (i >= b ? res[i-b] : 1);

	for (int i = 0; ; ++i) {
	  if (res[i] >= n) {
	    cout << i << endl;
	    break;
	  }
	}
    }
    return 0;
}
