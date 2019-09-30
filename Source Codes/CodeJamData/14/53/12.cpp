#include <iostream>
#include <cstdio>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <bitset>
#include <cmath>
#include <ctime>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 1100;
const int inf = 1000000000;
int n;
string s[maxN];
int id[maxN];

void read_data(int test) {
	cin >> n;
	vector < int > ids;
	for (int i = 0; i < n; ++i) {
		cin >> s[i];
		cin >> id[i];
		if (id[i] > 0) {
			ids.push_back(id[i]);
		}
	}
}

int res = inf;

void rec(int have, long long in, long long out, int last_used) {
	if (have == n) {
		int cnt = 0;
		for (int i = 0; i <= last_used; ++i) {
			if (in & (1LL << i)) {
				++cnt;
			}
		}
		res = min(res, cnt);
		return ;
	}

	if (s[have] == "L") {
		if (id[have] > 0) {
			if (out & (1LL << id[have])) {
				return ;
			}
			long long nin = in;
			long long nout = out;
			if (nin & (1LL << id[have])) {
				nin -= (1LL << id[have]);
			}
			nout |= (1LL << id[have]);
			rec(have + 1, nin, nout, last_used);
		} else {
			for (int i = 1; i <= last_used + 1; ++i) {
				if (out & (1LL << i)) {
					continue;
				}
				long long nin = in;
				long long nout = out;
				if (nin & (1LL << i)) {
					nin -= (1LL << i);
				}
				nout |= (1LL << i);
				rec(have + 1, nin, nout, max(last_used, i));
			}
		}
		return ;
	} else {
		if (id[have] > 0) {
			if (in & (1LL << id[have])) {
				return ;
			}
			long long nin = in;
			long long nout = out;
			if (nout & (1LL << id[have])) {
				nout -= (1LL << id[have]);
			}
			nin |= (1LL << id[have]);
			rec(have + 1, nin, nout, last_used);
		} else {
			for (int i = 1; i <= last_used + 1; ++i) {
				if (in & (1LL << i)) {
					continue;
				}
				long long nin = in;
				long long nout = out;
				if (nout & (1LL << i)) {
					nout -= (1LL << i);
				}
				nin |= (1LL << i);
				rec(have + 1, nin, nout, max(last_used, i));
			}
		}
		return ;
	}
}

void solve(int test) {
	cin >> n;
	vector < int > ids;
	for (int i = 0; i < n; ++i) {
		cin >> s[i];
		cin >> id[i];
		if (id[i] > 0) {
			ids.push_back(id[i]);
		}
	}
	sort(ids.begin(), ids.end());
	ids.resize(unique(ids.begin(), ids.end()) - ids.begin());

	map < int, int > M;
	for (int i = 0; i < ids.size(); ++i) {
		M[ids[i]] = i + 1;
	}

	for (int i = 0; i < n; ++i) {
		id[i] = M[id[i]];
	}

	long long in = 0, out = 0;
	res = inf;
	rec(0, in, out, ids.size());
	if (res == inf) {
		printf("Case #%d: CRIME TIME\n", test);
	} else {
		printf("Case #%d: %d\n", test, res);
	}
}

int main(int argc, char* argv[]) {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	//freopen("input.txt", "r", stdin);
	//freopen(argv[3], "w", stdout);

	int left_bound, right_bound;
	//sscanf(argv[1], "%d", &left_bound);
	//sscanf(argv[2], "%d", &right_bound);

	int tests;
	scanf("%d", &tests);
	left_bound = 1;
	right_bound = tests;
	for (int i = 1; i <= tests; ++i) {
		if (i >= left_bound && i <= right_bound) {
			solve(i);
			cerr << i << ": " << clock() << endl;
		} else {
			read_data(i);
		}
	}
	return 0;
}