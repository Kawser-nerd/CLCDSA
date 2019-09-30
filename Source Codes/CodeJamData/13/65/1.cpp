#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <bitset>
#include <set>
#include <string>
#include <map>
#include <cmath>
#include <queue>
#include <deque>
#include <ctime>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int P = 10007;
int n;
vector < int > a;

const int maxN = 105;
int d[maxN][maxN][maxN], c[maxN][maxN][maxN];
int f[maxN];
int w[1 << 20];

int calc(int mask) {
	if (w[mask] != -1) {
		return w[mask];
	}

	vector < int > order;
	for (int i = 0; i < n; ++i) {
		if (mask & (1 << i)) {
			order.push_back(a[i]);
		}
	}

	bool nice = true;
	for (int j = 1; j < order.size(); ++j) {
		if (order[j] > order[j - 1]) {
			nice = false;
			break;
		}
	}

	if (nice) {
		return w[mask] = 1;
	}

	int res = 0;
	for (int i = 0; i < n; ++i) {
		if (mask & (1 << i)) {
			res += calc(mask ^ (1 << i));
			if (res >= P) {
				res -= P;
			}
		}
	}

	return w[mask] = res;
}

int calc(int x, int y) {
	memset(d, 0, sizeof(d));
	d[0][0][0] = 1;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j <= i; ++j) {
			for (int last = 0; last <= i; ++last) {
				if (d[i][j][last] == 0) {
					continue;
				}

				if (i == x) {
					d[i + 1][j][last] += d[i][j][last];
					if (d[i + 1][j][last] >= P) {
						d[i + 1][j][last] -= P;
					}
				} else if (i == y) {
					if (last == 0 || a[last - 1] >= a[y]) {
						d[i + 1][j + 1][i + 1] += d[i][j][last];
						if (d[i + 1][j + 1][i + 1] >= P) {
							d[i + 1][j + 1][i + 1] -= P;
						}
					}
				} else if (i > y) {
					d[i + 1][j][last] += d[i][j][last];
					if (d[i + 1][j][last] >= P) {
						d[i + 1][j][last] -= P;
					}
					if (a[i] <= a[x] && (last == 0 || a[last - 1] >= a[i])) {
						d[i + 1][j + 1][i + 1] += d[i][j][last];
						if (d[i + 1][j + 1][i + 1] >= P) {
							d[i + 1][j + 1][i + 1] -= P;
						}
					}
				} else {
					d[i + 1][j][last] += d[i][j][last];
					if (d[i + 1][j][last] >= P) {
						d[i + 1][j][last] -= P;
					}
					if (last == 0 || a[last - 1] >= a[i]) {
						d[i + 1][j + 1][i + 1] += d[i][j][last];
						if (d[i + 1][j + 1][i + 1] >= P) {
							d[i + 1][j + 1][i + 1] -= P;
						}
					}
				}
			}
		}
	}

	/*memset(c, 0, sizeof(c));
	c[0][0][0] = 1;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j <= i; ++j) {
			for (int last = 0; last <= i; ++last) {
				if (c[i][j][last] == 0) {
					continue;
				}

				if (i >= x && i < y) {
					c[i + 1][j][last] += c[i][j][last];
					if (c[i + 1][j][last] >= P) {
						c[i + 1][j][last] -= P;
					}
				} else if (i == y) {
					if (last == 0 || a[last - 1] >= a[y]) {
						c[i + 1][j + 1][i + 1] += c[i][j][last];
						if (c[i + 1][j + 1][i + 1] >= P) {
							c[i + 1][j + 1][i + 1] -= P;
						}
					}
				} else if (i > y) {
					c[i + 1][j][last] += c[i][j][last];
					if (c[i + 1][j][last] >= P) {
						c[i + 1][j][last] -= P;
					}
					if (a[i] <= a[x] && (last == 0 || a[last - 1] >= a[i])) {
						c[i + 1][j + 1][i + 1] += c[i][j][last];
						if (c[i + 1][j + 1][i + 1] >= P) {
							c[i + 1][j + 1][i + 1] -= P;
						}
					}
				} else {
					c[i + 1][j][last] += c[i][j][last];
					if (c[i + 1][j][last] >= P) {
						c[i + 1][j][last] -= P;
					}
					if (last == 0 || a[last - 1] >= a[i]) {
						c[i + 1][j + 1][i + 1] += c[i][j][last];
						if (c[i + 1][j + 1][i + 1] >= P) {
							c[i + 1][j + 1][i + 1] -= P;
						}
					}
				}
			}
		}
	}*/

	int res = 0;
	for (int i = 1; i <= n; ++i) {
		for (int last = 1; last <= n; ++last) {
			if (d[n][i][last] == 0) {
				continue;
			}

			int current = d[n][i][last] * f[n - i - 1];
			current %= P;
			/*current += c[n][i][last] * f[n - i - 1];
			current %= P;*/
			res += current;
			if (res >= P) {
				res -= P;
			}
		}
	}
	return res;
}

int single(int x) {
	memset(d, 0, sizeof(d));
	d[0][0][0] = 1;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j <= i; ++j) {
			for (int last = 0; last <= i; ++last) {
				if (d[i][j][last] == 0) {
					continue;
				}

				if (i == x) {
					if (last != 0 && a[last - 1] < a[x]) {
						d[i + 1][j][last] += d[i][j][last];
						if (d[i + 1][j][last] >= P) {
							d[i + 1][j][last] -= P;
						}
					}
				} else {
					d[i + 1][j][last] += d[i][j][last];
					if (d[i + 1][j][last] >= P) {
						d[i + 1][j][last] -= P;
					}
					if (last == 0 || a[last - 1] >= a[i]) {
						d[i + 1][j + 1][i + 1] += d[i][j][last];
						if (d[i + 1][j + 1][i + 1] >= P) {
							d[i + 1][j + 1][i + 1] -= P;
						}
					}
				}
			}
		}
	}

	int res = 0;
	for (int i = 1; i <= n; ++i) {
		for (int last = 1; last <= n; ++last) {
			if (d[n][i][last] == 0) {
				continue;
			}

			int current = d[n][i][last] * f[n - i - 1];
			current %= P;
			res += current;
			if (res >= P) {
				res -= P;
			}
		}
	}

	return res;
}

void gen() {
	int test = 100;
	printf("%d\n", test);
	for (int i = 0; i < test; ++i) {
		int n = 3;
		printf("%d\n", n);
		for (int j = 0; j < n; ++j) {
			printf("%d ", rand() % 10000);
		}
		printf("\n");
	}
}

void solve(int test) {
	f[0] = 1;
	for (int i = 1; i < maxN; ++i) {
		f[i] = (f[i - 1] * i) % P;
	}
	cin >> n;
	a.resize(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	if (n > 20) {
		//return ;
	}

	memset(w, -1, sizeof(w));

	int res = 0;
	int ways = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			if (a[i] < a[j]) {
				res += calc(i, j);
				res %= P;
				++ways;
			}
		}
	}

	for (int i = 0; i < n; ++i) {
		res += single(i);
		res %= P;
	}

	if (ways == 0) {
		++res;
		res %= P;
	}

	printf("Case #%d: %d\n", test, res);
	if (n <= 20) {
		//printf("Case #%d: %d\n", test, calc((1 << n) - 1));
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	//gen();

	int tests;
	scanf("%d", &tests);
	for (int test = 0; test < tests; ++test) {
		solve(test + 1);
		cerr << test << endl;
	}

	cerr << "Time: " << clock() << endl;
	return 0;
}
