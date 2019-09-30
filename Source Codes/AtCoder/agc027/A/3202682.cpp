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

#define FOR(v, b, e)   for (int v = (b); v < (e); ++v)
#define REP(v, n)      FOR(v, 0, n)

#define ALL(c)         (c).begin(), (c).end()

typedef long long           ll;
typedef unsigned long long  ull;

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N;
	cin >> N;

	int x;
	cin >> x;

	vector<int> a(N);
	for (auto& i : a) cin >> i;

	sort(ALL(a));

	int result = N - 1;
	REP (i, N) {
		x -= a[i];
		if (x < 0) {
			result = i;
			break;
		}
	}

	if (x == 0) {
		cout << N << endl;
	} else {
		cout << result << endl;
	}
}