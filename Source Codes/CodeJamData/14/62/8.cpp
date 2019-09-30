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

long long res = 0;

vector<int> shorten(vector<int> a) {
  vector<int> b;
  REP (i, sz(a)/2)
    b.pb(a[2*i]/2);
  return b;
}

void solve(vector<int> a, int f) {
  if (sz(a) == 1) {
    long long add = 1;
    for (int u = 1; u <= f; ++u) {
      add *= u;
    }
    res += add;
    return;
  }
  vector<int> x;
  for(int i = 0; i < sz(a); i += 2) {
    if (a[i] % 2 || a[i]+1 != a[i+1]) {
      x.pb(i);
      if (sz(x) > 2) return;
    }
  }
  if (sz(x) == 0) {
    solve(shorten(a), f);
    return;
  }
  if (sz(x) == 1) {
    swap(a[x[0]], a[x[0]+1]);
    solve(shorten(a), f+1);
    return;
  }
  vector<int> p;
  p.pb(x[0]);
  p.pb(x[0]+1);
  p.pb(x[1]);
  p.pb(x[1]+1);
  REP (i, sz (p)) {
    REP (j, i) {
      swap(a[p[i]], a[p[j]]);
      if (a[x[0]] % 2 == 0 && a[x[0]]+1 == a[x[0]+1] && 
	  a[x[1]] % 2 == 0 && a[x[1]]+1 == a[x[1]+1]) {
	solve(shorten(a), f+1);
      }
      swap(a[p[i]], a[p[j]]);     
    }
  }
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
	
	vector<int> a(1<<n);
	REP (i, 1<<n) {
	  cin >> a[i];
	  a[i]--;
	}
	res = 0;
	solve(a, 0);
	cout << res << endl;
    }
    return 0;
}
