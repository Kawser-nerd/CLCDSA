#include <cstdio>
#include <iostream>
#include <cmath>

using namespace std;

int TESTS;
const double eps = 1e-6;
inline double sq(double a) { return a * a; }

int main()
{
	freopen ("B-large.in", "rt", stdin);
	freopen ("B-large.out", "wt", stdout);

	cin >> TESTS;
	for (int test = 1; test <= TESTS; ++test)
	{
		double dmin, tmin;
		double x0 = 0, vx = 0, y0 = 0, vy = 0, z0 = 0, vz = 0;
		int n;
		cin >> n;
		for (int i = 0; i < n; ++i) {
			double x, y, z;
			cin >> x >> y >> z;
			x0 += x;
			y0 += y;
			z0 += z;
			cin >> x >> y >> z;
			vx += x;
			vy += y;
			vz += z;
		}
		x0 /= n;
		y0 /= n;
		z0 /= n;
		vx /= n;
		vy /= n;
		vz /= n;
		double d = (vx * vx + vy * vy + vz * vz);
		if (d < eps) tmin = 0;
		else {
			tmin = - (vx * x0 + vy * y0 + vz * z0) / d;
			if (tmin < eps) tmin = 0;
		}
		dmin = sqrt (sq (x0 + vx * tmin) + sq (y0 + vy * tmin) + sq (z0 + vz * tmin));
		printf ("Case #%d: %.8lf %.8lf\n", test, dmin, tmin);
	}

	return 0;
}