// ??
//   ????????????????????????????????
//   ?????????????
// ???
//    ??pdf???
//    ???????????stack??????
//    x, y????????????????!!

#include <iostream>
#include <sstream>
#include <string>
#include <cassert>
#include <cmath>
#include <climits>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <algorithm>
#include <functional>
#include <numeric>
#include <iomanip>
#include <stack>

using namespace std;
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;

#define REP(i,n) for(int i = 0; i < (int)(n); ++i)
#define FOR(i,a,b) for(int i = (a); i < (int)(b); ++i)
#define ALL(c) (c).begin(), (c).end()
#define SIZE(v) ((int)v.size())

#define pb push_back
#define mp make_pair
#define mt make_tuple

int R, C, N;

bool on_border(int x, int y) {
    return (x == 0 || x == R) || (y == 0 || y == C);
}

// ???????????????
// ????????????????????????????
int coord_to_score(int x, int y) {
	if (y == 0) {
		return x;
	}
	else if (x == R) {
		return R + y;
	}
	else if (y == C) {
		return R + C + R - x;
	}
	else {
		return R + C + R + C - y;
	}
}

int main(void)
{
	cin.sync_with_stdio(false);
	cin >> R >> C >> N;

	map<int, int> score_to_idx;
	REP(n, N) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		// ???????????????????
		if (on_border(x1, y1) && on_border(x2, y2)) {
			score_to_idx[coord_to_score(x1, y1)] = n;
			score_to_idx[coord_to_score(x2, y2)] = n;
		}
	}
	stack<int> idxes;
	for (auto p : score_to_idx) {
		auto idx = p.second;
		if (SIZE(idxes) > 0 && idxes.top() == idx) {
			idxes.pop();
		}
		else {
			idxes.push(idx);
		}
	}

	cout << (SIZE(idxes) == 0 ? "YES" : "NO") << endl;
    return 0;
}