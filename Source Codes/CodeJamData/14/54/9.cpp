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
typedef vector<pii> vpii;
typedef long long ll;

string problemName = "D";
string smallFileName = problemName + "-small-attempt0";
string largeFileName = problemName + "-large";

const int inf = 1000000000;

//string fileName(1, tolower(problemName[0]));
string fileName = smallFileName;
//string fileName = largeFileName;

string inputFileName = fileName + ".in";
string outputFileName = fileName + ".out";

int c[128];
vpii a[128];
int n;
bool used[128];
int was[128];

int dfs(int x, int y, bool ret) {
  int add = 0;
  if (!was[x]) {
    add += c[x];
  }
  was[x]++;
  int best = -inf;
  REP (i, sz(a[x])) {
    int newx = a[x][i].X;
    int edge = a[x][i].Y;
    if (used[edge]) continue;
    used[edge] = true;
    int val = dfs(y, newx, false);
    if (best < add - val) {
      best = add - val;
    }
    used[edge] = false;
  }
  if (best == -inf) {
    if (ret) {
      best = add;
    } else {
      best = add - dfs(y, x, true);
    }
  }
  was[x]--;
  return best;
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
	cin >> n;
	REP (i, n) {
	  a[i].clear();
	}
	REP (i, n) {
	  cin >> c[i];
	}
	REP (i, n-1) {
	  int v;
	  cin >> v;
	  --v;
	  a[i].pb(pii(v, i));
	  a[v].pb(pii(i, i));
	}
	int best = -inf;
	REP (i, n) {	  
	  int best2 = -inf;
	  REP (j, n) {
	    best2 = max(best2, -dfs(i, j, false));
	  }
	  best = max(best, -best2);
	}
	cout << best << endl;
    }
    return 0;
}
