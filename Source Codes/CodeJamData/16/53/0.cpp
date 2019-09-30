#include <cstdio>
#include <iostream>
#include <ctime>
#include <iomanip>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cstring>
using namespace std;

int n1[11000000];
double l[1100][1100], r[1100][1100];
double mi[1100], ma[1100];
int x[1100], y[1100], z[1100], vx[1100], vy[1100], vz[1100];
int n;
int S;

bool can(double T) {
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (i != j) {
				double A = (vx[i] - vx[j]) * (vx[i] - vx[j]) + (vy[i] - vy[j]) * (vy[i] - vy[j]) + (vz[i] - vz[j]) * (vz[i] - vz[j]);
				double B = 2 * (x[i] - x[j]) * (vx[i] - vx[j]) + 2 * (y[i] - y[j]) * (vy[i] - vy[j]) + 2 * (z[i] - z[j]) * (vz[i] - vz[j]);
				double C = (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]) + (z[i] - z[j]) * (z[i] - z[j]) - T;
				if (A < 1e-9) {
					if (C < 0)
						l[i][j] = 0, r[i][j] = 1e9;
					else
						l[i][j] = 1e9, r[i][j] = -1e9;
				}else 
				if (B * B - 4 * A * C > 0) {
					l[i][j] = (-B - sqrt(B * B - 4 * A * C)) / 2 / A;
					r[i][j] = (-B + sqrt(B * B - 4 * A * C)) / 2 / A;
				}else {
					l[i][j] = 1e9;
					r[i][j] = -1e9;
				}
				// printf("%d %d %.8lf %.8lf\n", i, j, l[i][j], r[i][j]);
			}
	for (int i = 1; i <= n; i++)
		mi[i] = 1e9, ma[i] = -1e9;
	mi[1] = 0;
	ma[1] = S;
	int q = 1, h = 1;
	n1[q] = 1;
	while (q <= h) {
		// printf("%d %d\n", q, h);
		// for (int i = 1; i <= n; i++)
		// 	printf("%.9lf %.9lf\n", mi[i], ma[i]);
		for (int i = 1; i <= n; i++)
			if (i != n1[q] && l[n1[q]][i] < r[n1[q]][i]) {
				double L = max(mi[n1[q]], l[n1[q]][i]), R = min(ma[n1[q]], r[n1[q]][i]);
				// printf("%.8lf %.8lf\n", L, R);
				if (L < R) {
					R = r[n1[q]][i];
					// R = min(1e9 - S, max(ma[n1[q]], r[n1[q]][i]));
					if (L < mi[i] - 1e-9 || R + S > ma[i] + 1e-9) {
						// bool fi = false;
						// for (int j = q; j <= h; j++)
						// 	if (n1[j] == i)
						// 		fi = true;
						// if (!fi)
							n1[++h] = i;
						mi[i] = min(mi[i], L);
						ma[i] = max(ma[i], R + S);
					}
				}
			}
		q += 1;
	}
	return mi[2] < ma[2];
}

void doit() {
	scanf("%d%d", &n, &S);
	for (int i = 1; i <= n; i++)
		scanf("%d%d%d%d%d%d", &x[i], &y[i], &z[i], &vx[i], &vy[i], &vz[i]);
	// printf("xxx\n");
	double l = 0, r = 9000000, mid;
	for (int i = 1; i <= 100; i++) {
		mid = (l + r) / 2;
		if (can(mid))
			r = mid;
		else
			l = mid;
	}
	printf("%.8lf\n", sqrt(r));
	// printf("%d\n", can(2));
	// printf("%d\n", can(4));
}

int main() {
	int T;
	scanf("%d", &T);
	for (int i = 1; i <= T; i++) {
		printf("Case #%d: " , i);
		doit();
	}
}
