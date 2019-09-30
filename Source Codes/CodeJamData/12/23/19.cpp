#include <stdio.h>
#include <stdlib.h>
#include "time.h"
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef long long LL;

int n;
LL vals[600];
const int iters = 10000000;
pair<LL, int> sums[iters];

LL color[600];
LL tmp = 0;

vector<LL> generateRandomWithProof(int cnt) {
	++tmp;
	vector<LL> res;
	for (int it = 0; it < cnt; ++it) {
			int cur = rand() % n;
			while (color[cur] == tmp) {
				cur = rand() % n;
			}
			res.push_back(vals[cur]);
			color[cur] = tmp;
		}
	return res;
}

LL generateRandom(int cnt) {
	++tmp;
	LL sum = 0;
	for (int it = 0; it < cnt; ++it) {
		int cur = rand() % n;
		while (color[cur] == tmp) {
			cur = rand() % n;
		}
		sum += vals[cur];
		color[cur] = tmp;
	}
	return sum;
}

void gen() {
	for (int it = 50; ; ++it) {
		cerr << ".";
		srand(it);
		for (int i = 0; i < iters; ++i) {
			sums[i] = make_pair(generateRandom(it), i);
		}
		sort(sums, sums + iters);
		for (int i = 1; i < iters; ++i) {
			if (sums[i].first == sums[i - 1].first) {
				cerr << sums[i].second << " " << sums[i - 1].second << endl;
				srand(it);
				cout << "\n";
				int indA = sums[i].second, indB = sums[i - 1].second;
				for (int j = 0; j < iters; ++j) {
					if (j == indA || j == indB) {
						vector<LL> cur = generateRandomWithProof(it);
						sort(cur.begin(), cur.end());
						for (size_t k = 0; k < cur.size(); ++k) {
							cout << cur[k] << " ";
						}
						cout << "\n";
						LL sum = 0;
						for (size_t k = 0; k < cur.size(); ++k) {
							sum += cur[k];
						}
						cerr << sum << endl;
					} else {
						generateRandom(it);
					}
				}
				return;
			}
		}
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int tc;
	cin >> tc;
	for (int it = 0; it < tc; ++it) {
		cerr << it << endl;
		cout << "Case #" << it + 1 << ": ";
		cin >> n;
		for (int i = 0; i < n; ++i) {
			cin >> vals[i];
		}
		gen();
	}
	return 0;
}
