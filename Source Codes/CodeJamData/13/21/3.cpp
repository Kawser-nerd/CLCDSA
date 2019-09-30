#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; ++test) {
		cout << "Case #" << test << ": ";
		int a, n;
		cin >> a >> n;
		vector < int > p(n);
		for (int i = 0; i < n; ++i) {
			cin >> p[i];
		}

		sort(p.begin(), p.end());


		int res = 1000000000;

		for (int i = 0; i <= n; ++i) {
			int cur = n - i;
			int s = a;
			for (int j = 0; j < i; ++j) {
				if (s == 1) {
					cur = 1000000000;
					break;
				}
				while (s <= p[j]) {
					s += s - 1;
					++cur;
				}
				s += p[j];
			}
			res = min(res, cur);
		}

		cout << res << endl;
	}
	return 0;
}