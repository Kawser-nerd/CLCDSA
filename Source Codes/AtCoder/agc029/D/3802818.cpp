#include <cstdio>
#include <vector>
#include <stack>
#include <iostream>
#include <string>
#include <tuple>
#include <random>
#include <map>
#include <queue>
#include <set>
#include <complex>
#include <algorithm>
#include <cassert>
#include <iterator>
#include <numeric>
#include <cmath>
#include <stdio.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll> T;

const double eps = 1e-8;

const ll INF = 1e15;
const ll MOD = 1e9 + 7;

int main() {
	ll H, W, N;
	cin >> W >> H >> N;
	vector<set<ll>> sets(H);
	for (int i = 0;i < N;i++) {
		ll x, y;
		cin >> x >> y;
		x--;
		y--;
		sets[y].insert(x);
	}
	for (int y = 0;y < H;y++)
		sets[y].insert(W);
	ll answer = INF;
	ll y = 0;
	ll x = 0;
	while (true) {
		if (sets[y].lower_bound(x) == sets[y].end())
			break;
		ll near = *sets[y].lower_bound(x);
		answer = min(answer, near);
		x++;
		if (x >= W)
			break;
		if (sets[y].find(x) != sets[y].end())
			break;
		if (y >= H - 1)
			break;
		if (sets[y + 1].find(x) == sets[y + 1].end())
			y++;
		if (y >= H || x >= W)
			break;
	}
	cout << answer << endl;
	return 0;
}