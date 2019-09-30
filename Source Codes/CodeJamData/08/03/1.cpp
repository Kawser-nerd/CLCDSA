#include <cstdio>
#include <cmath>
using namespace std;

#define REP(i,n) for (int i = 0; i < (n); i++)
typedef long double real;

real dist(real x, real y) {
	return sqrt(x * x + y * y);
}

real triangle(real dist, real begin, real end) {
	return dist * (end - begin) * 0.5L;
}

real anglebyx(real x, real r) {
	return acos(x/r);
}

real anglebyy(real y, real r) {
	return asin(y/r);
}

real other(real c, real r) {
	return sqrt(r*r - c*c);
}

real slice(real alpha, real beta, real r) {
	return r * r * (beta - alpha) * 0.5L;
}

real part(real x, real y, real r) {
	return slice(anglebyy(y, r), anglebyx(x, r), r) - triangle(y, x, other(y, r)) - triangle(x, y, other(x, r));
}

real area(real x, real y, real a, real r) {
	if (dist(x + a, y + a) <= r)
		return a * a;
	if (dist(x, y) >= r)
		return 0;
	bool upperleft = dist(x, y + a) <= r;
	bool lowerright = dist(x + a, y) <= r;
	if (upperleft && lowerright) {
		real interx = other(y + a, r);
		real intery = other(x + a, r);
		return a * a - (x + a - interx) * (y + a - intery) + part(interx, intery, r);
	} else if (upperleft) {
		real interx = other(y + a, r);
		return a * (interx - x) + part(interx, y, r);
	} else if (lowerright) {
		real intery = other(x + a, r);
		return a * (intery - y) + part(x, intery, r);
	} else
		return part(x, y, r);
}

int main() {
	int zzz;
	scanf("%d", &zzz);
	REP(zz,zzz) {
		real f, R, t, r, g;
		scanf("%llf%llf%llf%llf%llf", &f, &R, &t, &r, &g);
		real rad = R - t - f;
		real side = g - 2 * f;
		real skip = g + 2 * r;
		real off = r + f;
		real res = 0;
		if (side > 0) {
			int i = 0;
			for (;;) {
				int j = 0;
				for (;;) {
					real ar = area(off + i * skip, off + j * skip, side, rad);
					if (ar == 0)
						break;
					res += ar;
					j++;
				}
				if (!j)
					break;
				i++;
			}
		}
		printf("Case #%d: %.30llf\n", zz+1, 1.0L - res / (R * R * M_PI * 0.25L));
	}
}
