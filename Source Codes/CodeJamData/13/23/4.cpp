#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

vector < string > dict;

const int inf = 1000000000;
const int maxN = 5000;
const int maxL = 6;
int d[maxN][maxL];

int solve(string s) {
	for (int i = 0; i < maxN; ++i) {
		for (int j = 0; j < maxL; ++j) {
			d[i][j] = inf;
		}
	}

	d[0][maxL - 1] = 0;
	for (int i = 0; i < s.size(); ++i) {
		cerr << i << endl;
		for (int j = 0; j < maxL; ++j) {
			if (d[i][j] == inf) {
				continue;
			}

			for (int k = 0; k < dict.size(); ++k) {
				if (s.size() - i < dict[k].size()) {
					continue;
				}

				const string& current = dict[k];
				int first = inf, last = -inf;
				bool nice = true;

				int changes = 0;
				for (int l = 0; l < current.size(); ++l) {
					if (s[i + l] != current[l]) {
						++changes;
						first = min(first, l);
						if (l - last < 5) {
							nice = false;
							break;
						}
						if (first + j + 1 < 5) {
							nice = false;
							break;
						}
						last = l;
					}
				}

				if (nice) {
					int id = maxL - 1;
					if (last == -inf) {
						id = min(id, (int)(current.size()) + j);
					} else {
						id = min(id, (int)(current.size()) - last - 1);
					}
					d[i + current.size()][id] = min(d[i + current.size()][id], d[i][j] + changes);
				}
			}
		}
	}

	int res = inf;
	for (int i = 0; i < maxL; ++i) {
		res = min(res, d[s.size()][i]);
	}
	return res;
}

int main() {
	freopen("garbled_email_dictionary.txt", "r", stdin);
	string s;
	for (int i = 0; i < 521196; ++i) {
		cin >> s;
		dict.push_back(s);
	}
	cerr << dict.size() << endl;

	//freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int tests;
	cin >> tests;
	cerr << tests << endl;
	for (int test = 1; test <= tests; ++test) {
		cout << "Case #" << test << ": ";
		string s;
		cin >> s;
		cout << solve(s) << endl;

		cerr << test << endl;
	}
	return 0;
}