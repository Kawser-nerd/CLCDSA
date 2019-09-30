#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <set>
using namespace std;

#include <math.h>
#include <stdio.h>
int solve(int R, int C, int a1, int a2, int a3, int a4, int N) {
	int all = R * C;
	int res = R * C * 2 - R - C;

	N = all - N;

	if (a1 + a2 * 2 + a3 * 3 + a4 * 4 != res) {
		fprintf(stderr, "Warning ! unexpected result!");
	}

	if (N >= a4) {
		N -= a4;
	}
	else {
		a4 = N; N = 0;
	}
	if (N >= a3) {
		N -= a3;
	}
	else {
		a3 = N; N = 0;
	}
	if (N >= a2) {
		N -= a2;
	}
	else {
		a2 = N; N = 0;
	}

	if (N >= a1) {
		N -= a1;
	}
	else {
		a1 = N; N = 0;
	}
	res = res - a4 * 4 - a3 * 3 - a2 * 2 - a1;
	return res;
}
int main(){
	freopen("B-large.in", "r", stdin);
	freopen("B-large.out", "w", stdout);
	int T;
	scanf("%d", &T);
	for (int cs = 1; cs <= T; cs++) {
		int R, C, N;
		scanf("%d %d %d", &R, &C, &N);

		if (R < C) {
			R ^= C ^= R ^= C;
		}
		int a4, a3, a2, a1;
		int b4, b3, b2, b1;
		a4 = a3 = a2 = a1 = b4 = b3 = b2 = b1 = 0;
		if (R == 1 && C == 1) {
		}
		else {
			for (int i = 0; i < R; i++) {
				int a_all = 0;
				int b_all = 0;
				if (i % 2 == 0) {
					a_all = (C + 1) / 2;
					b_all = C - a_all;
					if (i == 0 || i == R - 1) {
						int a2pl = 0, b2pl = 0;
						if (C % 2 == 1) {
							a2pl = (C == 1) ? 1 : 2;
							b2pl = 0;
						}
						else {
							a2pl = 1;
							b2pl = 1;
						}
						int a3pl = a_all - a2pl;
						int b3pl = b_all - b2pl;

						if (C == 1) {
							a1 += a2pl;
							b1 += b2pl;
						}
						else {
							a2 += a2pl;
							b2 += b2pl;
						}
						a3 += a3pl;
						b3 += b3pl;
					}
					else {
						int a3pl, b3pl;
						a3pl = b3pl = 0;
						if (C % 2 == 1) {
							a3pl = (C == 1) ? 1 : 2;
							b3pl = 0;
						}
						else {
							a3pl = 1;
							b3pl = 1;
						}

						int a4pl = a_all - a3pl;
						int b4pl = b_all - b3pl;

						if (C == 1) {
							a2 += a3pl;
							b2 += b3pl;
						}
						else {
							a3 += a3pl;
							b3 += b3pl;
						}
						a4 += a4pl;
						b4 += b4pl;
					}
				}
				else {
					b_all = (C + 1) / 2;
					a_all = C - b_all;
					if (i == 0 || i == R - 1) {
						int a2pl = 0, b2pl = 0;
						if (C % 2 == 1) {
							a2pl = 0;
							b2pl = (C == 1) ? 1 : 2;
						}
						else {
							a2pl = 1;
							b2pl = 1;
						}
						int a3pl = a_all - a2pl;
						int b3pl = b_all - b2pl;
						if (C == 1) {
							a1 += a2pl;
							b1 += b2pl;
						}
						else {
							a2 += a2pl;
							b2 += b2pl;
						}
						a3 += a3pl;
						b3 += b3pl;
					}
					else {
						int a3pl, b3pl;
						a3pl = b3pl = 0;
						if (C % 2 == 1) {
							a3pl = 0;
							b3pl = (C == 1) ? 1 : 2;
						}
						else {
							a3pl = 1;
							b3pl = 1;
						}

						int a4pl = a_all - a3pl;
						int b4pl = b_all - b3pl;

						if (C == 1) {
							a2 += a3pl;
							b2 += b3pl;
						}
						else {
							a3 += a3pl;
							b3 += b3pl;
						}
						a4 += a4pl;
						b4 += b4pl;
					}
				}
			}
		}
		printf("Case #%d: %d\n", cs, min(solve(R, C, a1, a2, a3, a4, N), solve(R, C, b1, b2, b3, b4, N)));
	}
	return 0;
}