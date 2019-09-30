#include <iostream>
#include <cmath>
#include <vector>
#include <cstdio>

using namespace std;

long double aPoly(vector <long double> x, vector <long double> y) {
	long double r = 0.0;
	for (int i = 1; i < x.size(); i++) {
		r += x[i] * y[i - 1] - x[i - 1] * y[i];
	}
	if (r < 0.0) r = -r;
	return (r / 2.0);
}

long double aArc(vector <long double> a) {
	long double da = a[1] - a[0];
	return (da - sin(da)) / 2.0;
}

long double getArea(long double x1, long double x2, long double y1, long double y2, long double R) {
	long double R2 = R * R;
	vector <long double> x;
	vector <long double> y;
	vector <long double> an;
	x.push_back(x1);
	y.push_back(y1);
	int a[4];
	a[0] = (x1 * x1 + y1 * y1 < R2);
	a[1] = (x2 * x2 + y1 * y1 < R2);
	a[2] = (x2 * x2 + y2 * y2 < R2);
	a[3] = (x1 * x1 + y2 * y2 < R2);
	if (a[0] && (!a[1])) {
		x.push_back(sqrt(R2 - y1 * y1));
		y.push_back(y1);
		an.push_back(asin(y1 / R));
	}
	if (a[1]) {
		x.push_back(x2);
		y.push_back(y1);
	}
	if (a[1] && (!a[2])) {
		x.push_back(x2);
		y.push_back(sqrt(R2 - x2 * x2));
		an.push_back(acos(x2 / R));
	}
	if (a[2]) {
		x.push_back(x2);
		y.push_back(y2);
	}
	if (a[3] && (!a[2])) {
		x.push_back(sqrt(R2 - y2 * y2));
		y.push_back(y2);
		an.push_back(asin(y2 / R));
	}
	if (a[3]) {
		x.push_back(x1);
		y.push_back(y2);
	}
	if (a[0] && (!a[3])) {
		x.push_back(x1);
		y.push_back(sqrt(R2 - x1 * x1));
		an.push_back(acos(x1 / R));
	}
	x.push_back(x[0]);
	y.push_back(y[0]);
	return (aPoly(x, y) + R2 * aArc(an));
}

long double getProb(long double f, long double R, long double t, long double r, long double g) {
	if (g <= 2.0 * f) return 1.0;
	long double s = g + 2.0 * r;
	long double d = (g - 2.0 * f) / 2.0;
	long double R2 = R - t - f;
	long double R22 = R2 * R2;
	int k = (int)(R / s) + 3;
	int c = 0;
	long double z1 = 0.0;
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < k; j++) {
			long double x1 = s * i + s / 2.0 - d;
			long double x2 = s * i + s / 2.0 + d;
			long double y1 = s * j + s / 2.0 - d;
			long double y2 = s * j + s / 2.0 + d;
			if (x2 * x2 + y2 * y2 <= R22) {
				c++;
			} else if (x1 * x1 + y1 * y1 < R22) {
				z1 += getArea(x1, x2, y1, y2, R2);
			}
		}
	}
	long double freeArea = c * (4.0 * d * d) + z1;
	long double totalArea = M_PI * R * R / 4.0;
	return 1.0 - freeArea / totalArea;
}

int main() {
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		long double f, R, t, r, g;
		cin >> f >> R >> t >> r >> g;
		long double P = getProb(f, R, t, r, g);
		printf("Case #%d: %.8llf\n", i, P);
	}
}

