#include <utility>
#include <bitset>
#include <string>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <numeric>
#include <iostream>
#include <ios>
#include <iomanip>
#include <sstream>
#include <climits>
#include <cmath>

using namespace std;

#ifdef USE_LOG
#define LOG(str)  cout << str << endl
#define DMP(var)  cout << #var << " = " << var << endl
#else
#define LOG(...)
#define DMP(...)
#endif

#define FOR(v, b, e)   for (int v = (b); v < (e); ++v)
#define RFOR(v, b, e)  for (int v = (e) - 1; (b) <= v; --v)
#define REP(v, n)      FOR(v, 0, n)
#define RREP(v, n)     RFOR(v, 0, n)

#define ALL(c)         (c).begin(), (c).end()

typedef long long           ll;
typedef unsigned long long  ull;

int main () {
	ios::sync_with_stdio(false);
	cin.tie(0);

	string N;
	cin >> N;

	int r = 0;
	int t = 0;
	REP (i, N.length()) {
		t += N[i] - '0';
	}

	r = t;

	FOR (i, 0, N.length() - 1) {
		t = 0;
		FOR (j, 0, i) {
			t += N[j] - '0';
		}
		t += (N[i] - '0') - 1;
		t += 9 * (N.length() - (i + 1));
		r = max(t, r);
	}

	cout << r << endl;
}