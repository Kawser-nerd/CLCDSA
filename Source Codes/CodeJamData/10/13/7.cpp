//ref: http://www.research.att.com/~njas/sequences/A005206

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

bool canwin[40][40];

int test()
{
	for (int i = 0; i < 40; ++i) {
		canwin[i][0] = true;
	}
	for (int j = 1; j < 40; ++j) {
		for (int i = 1; i <= j; ++i) {
			bool cw = false;
			for (int k = 1; ; ++k) {
				int ni = i - j * k;
				if (ni <= 0) break;
				if (ni > 0 && !canwin[max(j, ni)][min(j, ni)]) cw = true;
			}
			for (int k = 1; ; ++k) {
				int nj = j - i * k;
				if (nj <= 0) break;
				if (nj > 0 && !canwin[max(nj, i)][min(nj, i)]) cw = true;
			}
			canwin[j][i] = cw;
		}
	}
	for (int i = 1; i < 40; ++i) {
		for (int j = 1; j <= i; ++j) {
			if (canwin[i][j] && !canwin[i][j + 1]) {
				printf("%d %d\n", i, j);
				break;
			}
		}
	}
	return 0;
}

double tau = (1 + sqrt(5.0)) / 2;

long long run()
{
	int a1, a2, b1, b2;
	scanf("%d %d %d %d", &a1, &a2, &b1, &b2);
	long long ret = 0;
	for (int a = a1; a <= a2; ++a) {
		int l = int(floor(a * tau - a) + 0.1);
		if (b1 <= l) {
			if (b2 > l) {
				ret += (l - b1 + 1);
			}
			else {
				ret += (b2 - b1 + 1);
			}
		}
	}
	swap(a1, b1);
	swap(a2, b2);
	for (int a = a1; a <= a2; ++a) {
		int l = int(floor(a * tau - a) + 0.1);
		if (b1 <= l) {
			if (b2 > l) {
				ret += (l - b1 + 1);
			}
			else {
				ret += (b2 - b1 + 1);
			}
		}
	}
	return ret;
}

int main()
{
	freopen("C2.in", "r", stdin);
	freopen("C2.out", "w", stdout);
	//printf("%.20lf\n", tau);
	int t;
	scanf("%d", &t);
	for (int i = 1; i <= t; ++i) {
		printf("Case #%d: %lld\n", i, run());
	}
	//test();
	return 0;
}