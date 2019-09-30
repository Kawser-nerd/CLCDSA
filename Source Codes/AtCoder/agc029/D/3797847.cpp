#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <iomanip>

#define FOR(i, a, b) for(decltype(b) i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;

using namespace std;

#ifdef INPUT
#include <sstream>
stringstream input(R"(
3 3 1
3 2
)");
#define cin input
#endif

int main()
{
	int h, w, n;
	cin >> h >> w >> n;

	vector<set<int>> s(h);

	REP (i, n)
	{
		int x, y;
		cin >> x >> y;
		s[x - 1].insert(y - 1);
	}

	int x, y = 0;

	for (x = 0; x < h; ++x)
	{
		auto it = s[x].upper_bound(y);
		if (it != s[x].begin())
			break;
		if (x && (it == s[x].end() || *it != y + 1))
			++y;
	}

	cout << x << endl;

	return 0;
}