#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <cmath>

using namespace std;

struct tComplex {
	double re, im;

	tComplex (double _re, double _im) { re = _re; im = _im; }
	tComplex operator * (tComplex b) {
		return tComplex (re * b.re - im * b.im, re * b.im + im * b.re);
	}
	tComplex operator / (tComplex b) {
		return tComplex ((re * b.re + im * b.im) / (b.re * b.re + b.im * b.im), (-re * b.im + im * b.re) / (b.re * b.re + b.im * b.im));
	}
	tComplex operator - (tComplex b) { return tComplex (re - b.re, im - b.im); }
	tComplex operator + (tComplex b) { return tComplex (re + b.re, im + b.im); }
};

double xa1, ya1, xa2, ya2, xa3, ya3;
double xb1, yb1, xb2, yb2, xb3, yb3;

void read_data () {
	cin >> xa1 >> ya1 >> xa2 >> ya2 >> xa3 >> ya3;
	cin >> xb1 >> yb1 >> xb2 >> yb2 >> xb3 >> yb3;
}

void solve () {
	tComplex p1 (xa1, ya1); tComplex p2 (xa2, ya2); tComplex p3 (xa3, ya3);
	tComplex q1 (xb1, yb1); tComplex q2 (xb2, yb2); tComplex q3 (xb3, yb3);

	tComplex z1 (0.0, 0.0), z2 (0.0, 0.0), x (0.0, 0.0), e (1.0, 0.0);

	z1 = (q1 - q2) / (p1 - p2);
	z2 = q1 - p1 * z1;

	x = z2 / (e - z1);

	cout << setiosflags (ios::fixed) << setprecision (10) << x.re << " " << x.im << endl;
}

int main () {
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);

	int T;
	cin >> T;

	for (int t = 0; t < T; ++t) {
		cout << "Case #" << t+1 << ": ";

		read_data ();
		solve ();
	}

	return 0;
}
