#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <bitset>
#include <queue>
#include <cmath>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 15;
vector < vector < int > > combinations;
vector < vector < int > > subs;
vector < vector < int > > ways;

vector < int > order;

vector < int > a;
long long R, N, M, K;
long long res = 0;

void rec(int have = 0) {
	if (have == N) {
		order.push_back(combinations.size());
		combinations.push_back(a);
		return ;
	}

	for (int i = (have == 0 ? 2 : a[have - 1]); i <= M; ++i) {
		a[have] = i;
		rec(have + 1);
	}
}

long long f(int n) {
	long long res = 1;
	for (int i = 1; i <= n; ++i) {
		res *= (long long)(i);
	}
	return res;
}

double getProbability(int index) {
	long long total = f(12);
	int l = 0;
	for (int i = 1; i <= 12; ++i) {
		if (i == 12 || combinations[index][i] > combinations[index][i - 1]) {
			total /= f(i - l);
			l = i;
		}
	}

	long long ways = 1;
	for (int i = 1; i <= 12; ++i) {
		ways *= 7LL;
	}

	return (double)(ways - total) / (double)(ways);
}

bool comp(int x, int y) {
	return getProbability(x) < getProbability(y) - 1e-9;
}

double cnk(int n, int k) {
	double res = 1.0;
	for (int i = 1; i <= k; ++i) {
		res *= (double)(n + 1 - i);
		res /= (double)(i);
	}
	return res;
}

void solve(int test) {
	cout << "Case #" << test << ":" << endl;
	cin >> R >> N >> M >> K;
	//R = 8000;
	//N = 12;
	//M = 8;
	//K = 12;

	int solved = 0;
	for (int step = 0; step < R; ++step) {
		map < long long, int > ps;
		for (int i = 0; i < K; ++i) {
			long long x;
			cin >> x;
			++ps[x];
		}

		bool found = false;
		vector < pair < double, int > > options;
		for (int ind = 0; ind < combinations.size(); ++ind) {
			int index = order[ind];
			bool nice = true;
			double p = 1.0 - getProbability(index);
			for (map < long long, int > ::iterator it = ps.begin(); it != ps.end(); ++it) {
				int pos = lower_bound(subs[index].begin(), subs[index].end(), (int)(it->first)) - subs[index].begin();
				if (pos == subs[index].size() || subs[index][pos] != (int)(it->first)) {
					nice = false;
					break;
				}

				p *= cnk(ways[index][pos], it->second);
			}

			if (nice) {
				options.push_back(make_pair(-p, index));
			}
		}

		sort(options.begin(), options.end());

		if (options.size() == 0) {
			for (int i = 0; i < N; ++i) {
				printf("%d", 2);
			}
			printf("\n");
		} else {
			for (int i = 0; i < N; ++i) {
				printf("%d", combinations[options[0].second][i]);
			}
			//printf(": %d\n", options.size());
			printf("\n");
		}
		cerr << step << endl;
	}

	cerr << "Solved: " << solved << endl;
}

void precalc() {
	subs.assign(combinations.size(), vector < int > (0));
	ways.assign(combinations.size(), vector < int > (0));
	for (int index = 0; index < combinations.size(); ++index) {
		map < int, int > used;
		for (int i = 0; i < (1 << N); ++i) {
			long long current = 1LL;
			int bits = 0;
			for (int j = 0; j < N; ++j) {
				if (i & (1 << j)) {
					current *= (long long)(combinations[index][j]);
					++bits;
				}
			}
			//if (bits >= 3 && bits <= 9) {
				++used[current];
			//}
		}

		subs[index].assign(used.size(), 0);
		ways[index].assign(used.size(), 0);
		int cnt = 0;
		for (map < int, int > ::iterator it = used.begin(); it != used.end(); ++it) {
			subs[index][cnt] = it->first;
			ways[index][cnt ++] = it->second;
		}
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	N = 12;
	M = 8;
	a.assign(N, 0);
	rec();
	
	sort(order.begin(), order.end(), comp);
	//random_shuffle(combinations.begin(), combinations.end());
	precalc();
	cerr << "Precalc is done " << endl;

	int tests;
	scanf("%d\n", &tests);
	for (int i = 1; i <= tests; ++i) {
		solve(i);
	}
	return 0;
}