#include<cmath>
#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 500005;

int n;

long long fA, fB;

char map[N], f[10];

int s[N], x[N], y[N];

long long xx[N], yy[N];

long long dot(long long x0, long long y0, long long x1, long long y1) {
	return x0 * x1 + y0 * y1;
}

long long det(long long x0, long long y0, long long x1, long long y1) {
	return x0 * y1 - x1 * y0;
}

long long det(int i, int j, int k) {
	return det(xx[j] - xx[i], yy[j] - yy[i], xx[k] - xx[i], yy[k] - yy[i]);
}

int ord[N];

bool byXX(const int &i, const int &j) {
	return xx[i] < xx[j] || (xx[i] == xx[j] && yy[i] < yy[j]) || (xx[i] == xx[j] && yy[i] == yy[j] && j < i);
}

long long dA, dB;

int ans;

long long gcdll(long long a, long long b) {
	if (a == 0 || b == 0) {
		return a + b;
	}
	long long c = a % b;
	while (c) {
		a = b;
		b = c;
		c = a % b;
	}
	return b;
}

void cal(int l, int r, long long &a, long long &b) {
	if (l > r) {
		swap(l, r);
	}
	long long ta = s[r] - s[l], tb = r - l;
	a = ta * fB - tb * fA;
	b = tb * fB;
	if (a < 0) {
		a = -a;
	}
	long long g = gcdll(a, b);
	a /= g, b /= g;
}

int cmp(long long tA, long long tB, long long dA, long long dB) {
	if (tA == dA && tB == dB) {
		return 0;
	}
	if ((long double)tA / tB < (long double)dA / dB) {
		return -1;
	} else {
		return 1;
	}
}

bool better(int l1, int l2, int r) {
	long long tA0, tB0, tA1, tB1;
	cal(l1, r, tA0, tB0);
	cal(l2, r, tA1, tB1);
	return cmp(tA0, tB0, tA1, tB1) < 0 || (cmp(tA0, tB0, tA1, tB1) == 0 && l1 < l2);
}

inline void update(int a, int b) {
	//cout << "update" << a << ' ' << b << endl;
	if (a > b) {
		swap(a, b);
	}
	long long tA, tB;
	cal(a, b, tA, tB);
	if (cmp(tA, tB, dA, dB) < 0 || (cmp(tA, tB, dA, dB) == 0 && ans > a)) {
		ans = a;
		dA = tA;
		dB = tB;
	}
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%d%s%s", &n, f, map);
		fB = 1000000;
		fA = 0;
		for (int i = 0; i <= 7; ++i) {
			if (f[i] != '.') {
				fA = fA * 10 + f[i] - '0';
			}
		}
		long long g = gcdll(fB, fA);
		fB /= g, fA /= g;
		x[0] = 0, y[0] = 0, s[0] = 0;
		for (int i = 0; i < n; ++i) {
			x[i + 1] = i + 1;
			s[i + 1] = s[i] + map[i] - '0';
			y[i + 1] = s[i + 1];
		}
		for (int i = 0; i <= n; ++i) {
			xx[i] = dot(x[i], y[i], fA, -fB);
			yy[i] = dot(x[i], y[i], fB, fA);
		}
		for (int i = 0; i <= n; ++i) {
			ord[i] = i;
		}
		sort(ord, ord + n + 1, byXX);
		/*
		for (int i = 0; i <= n; ++i) {
			cout << ord[i] << ' ' << xx[ord[i]] << ' ' << yy[ord[i]] << endl;
		}*/
		dA = 1ll << 60;
		dB = 1;
		ans = 0;
		vector<int> con;
		for (int no = 0; no <= n; ++no) {
			int i = ord[no];
			if (con.size() > 0) {
				int l = 0, r = con.size() - 1;
				while (l < r) {
					int m = (l + r) >> 1;
					if (!better(con[m], con[m + 1], i)) {
						l = m + 1;
					} else {
						r = m;
					}
				}
				update(con[l], i);
			}
			while (con.size() > 1 && det(con[con.size() - 2], con[con.size() - 1], i) >= 0) {
				con.pop_back();
			}
			con.push_back(i);
		}
		con.clear();
		for (int no = n; no >= 0; --no) {
			int i = ord[no];
			if (con.size() > 0) {
				int l = 0, r = con.size() - 1;
				while (l < r) {
					int m = (l + r) >> 1;
					if (!better(con[m], con[m + 1], i)) {
						l = m + 1;
					} else {
						r = m;
					}
				}
				update(con[l], i);
			}
			while (con.size() > 1 && det(con[con.size() - 2], con[con.size() - 1], i) <= 0) {
				con.pop_back();
			}
			con.push_back(i);
		}
		static int id = 0;
		printf("Case #%d: %d\n", ++id, ans);
		cerr << t << endl;
	}
	return 0;
}
