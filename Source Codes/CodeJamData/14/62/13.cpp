#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
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

struct State {
	int l, r;
	int mask;
	State() {
	}
	State(int l, int r, int mask) : l(l), r(r), mask(mask) {
	}
	bool operator < (const State& other) const {
		return make_pair(make_pair(l, r), mask) < make_pair(make_pair(other.l, other.r), other.mask);
	}
};

map < State, long long > M;

void read_data(int test) {
}

const int maxN = 6000;
int n, a[maxN], b[maxN];

bool isSorted() {
	for (int i = 1; i < (1 << n); ++i) {
		if (a[i] < a[i - 1]) {
			return false;
		}
	}
	return true;
}

set < vector < int > > S;
vector < int > cur;

void rec(int mask) {
	if (isSorted()) {
		S.insert(cur);
	}
	if (mask == (1 << n) - 1) {
		return;
	}

	for (int i = 0; i < n; ++i) {
		if (mask & (1 << i)) {
			continue;
		}

		for (int j = 0; j + (1 << i) <= (1 << n); j += (1 << i)) {
			for (int k = j + (1 << i); k + (1 << i) <= (1 << n); k += (1 << i)) {
				cur.push_back(i);

				for (int x = j, y = k; x < j + (1 << i); ++x, ++y) {
					swap(a[x], a[y]);
				}

				rec(mask | (1 << i));

				for (int x = j, y = k; x < j + (1 << i); ++x, ++y) {
					swap(a[x], a[y]);
				}

				cur.pop_back();
			}
		}
	}
}

void brute(int test) {
	cin >> n;
	for (int i = 0; i < (1 << n); ++i) {
		cin >> a[i];
	}

	S.clear();
	rec(0);
	printf("Case #%d: %d\n", test, S.size());
}

set < int > A;

void calc(vector < int > a, int current, int mask) {
	if (a.size() == 1) {
		A.insert(mask);
		return;
	}

	vector < int > unsorted;
	for (int i = 0; i < a.size(); i += 2) {
		int x = a[i];
		int y = a[i + 1];
		if (y != x + 1) {
			unsorted.push_back(i);
			continue;
		}
		if (y % 2 != 0) {
			unsorted.push_back(i);
			continue;
		}
	}

	if (unsorted.size() > 2) {
		return;
	}
	if (unsorted.size() == 0) {
		vector < int > b;
		for (int i = 0; i < a.size(); i += 2) {
			b.push_back(a[i + 1] / 2);
		}
		calc(b, current + 1, mask);
		return;
	}

	if (unsorted.size() == 1) {
		int index = unsorted[0];
		swap(a[index], a[index + 1]);

		vector < int > b;
		for (int i = 0; i < a.size(); i += 2) {
			b.push_back(a[i + 1] / 2);
		}
		calc(b, current + 1, mask | (1 << current));
		return;
	}

	if (unsorted.size() == 2) {
		int x = unsorted[0];
		int y = unsorted[1];

		for (int u = x; u < x + 2; ++u) {
			for (int v = y; v < y + 2; ++v) {
				swap(a[u], a[v]);

				if (a[x + 1] == a[x] + 1 && a[x + 1] % 2 == 0 && a[y + 1] == a[y] + 1 && a[y + 1] % 2 == 0) {
					vector < int > b;
					for (int i = 0; i < a.size(); i += 2) {
						b.push_back(a[i + 1] / 2);
					}
					calc(b, current + 1, mask | (1 << current));
				}

				swap(a[u], a[v]);
			}
		}
	}
}

void clever(int test) {
	cin >> n;
	for (int i = 0; i < (1 << n); ++i) {
		cin >> a[i];
	}

	A.clear();
	vector < int > start(1 << n);
	for (int i = 0; i < (1 << n); ++i) {
		start[i] = a[i];
	}
	calc(start, 0, 0);

	long long res = 0;
	for (set < int > ::iterator it = A.begin(); it != A.end(); ++it) {
		int bits = 0;
		int mask = (*it);
		for (int i = 0; i < 20; ++i) {
			if (mask & (1 << i)) {
				++bits;
			}
		}
		long long current = 1;
		for (int i = 1; i <= bits; ++i) {
			current *= (long long)(i);
		}
		res += current;
	}

	cout << "Case #" << test << ": " << res << endl;
}

void solve(int test) {
	clever(test);
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
		}
		else {
			read_data(i);
		}
	}
	return 0;
}