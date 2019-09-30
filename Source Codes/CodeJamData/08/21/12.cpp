#include <cstdio>
#include <cmath>
#include <cctype>
#include <cstring>

#include <iostream>

#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <utility>

using namespace std;

typedef long long i64;

i64 x[1000000], y[1000000];

int main() {
	int T; scanf("%d", &T);
	for (int tt = 0; tt < T; ++tt) {
		int d[3][3];
		for (int i = 0; i < 3; ++i) {
			for (int j = 0; j < 3; ++j) {
				d[i][j] = 0;
			}
		}
		int n;
		i64 A, B, C, D, x0, y0, M;
		cin >> n >> A >> B >> C >> D >> x0 >> y0 >> M;
		x[0] = x0, y[0] = y0;
		for (int i = 1; i <= n - 1; ++i) {
			x[i] = ((A * x[i - 1] + B) % M);
			y[i] = ((C * y[i - 1] + D) % M);
		}
		/*x[0] = 0; y[0] = 0;
		x[1] = 0; y[1] = 3;
		x[2] = 3; y[2] = 3;
		x[3] = 3; y[3] = 0;
		n = 4;*/
		for (int i = 0; i <= n - 1; ++i) {
			++d[x[i] % 3][y[i] % 3];
		}
		/*
		for (int i = 0; i < 3; ++i) {
			for (int j = 0; j < 3; ++j) {
				cout << i << " " << j << " " << d[i][j] << endl;
			}
		}*/
		i64 result = 0;
		for (int i = 0; i < 9; ++i) {
			int x1 = i / 3, y1 = i % 3;
			for (int j = 0; j < 9; ++j) {
				int x2 = j / 3, y2 = j % 3;
				for (int k = 0; k < 9; ++k) {
					int x3 = k / 3, y3 = k % 3;
//						cout << i << " " << j << " " << k << endl;
					if (((x1 + x2 + x3) % 3 == 0) && ((y1 + y2 + y3) % 3 == 0)) {
						i64 t1 = d[x1][y1], t2 = d[x2][y2], t3 = d[x3][y3];
						if (i == j) --t2;
						if (i == k) --t3;
						if (j == k) --t3;
						result += t1 * t2 * t3;
					}
				}
			}
		}
		result /= 6;
		//int t = 0;
		/*
		for (int i = 0; i < n; ++i) {
			for (int j = i + 1; j < n; ++j) {
				for (int k = j + 1; k < n; ++k) {
					if (((x[i] + x[j] + x[k]) % 3 == 0) && ((y[i] + y[j] + y[k]) % 3 == 0)) {
						++t;
					}
				}
			}
		}*/
//		cout << t << endl;
		printf("Case #%d: ", tt + 1);
		cout << result << endl;
	}
	return 0;
}
