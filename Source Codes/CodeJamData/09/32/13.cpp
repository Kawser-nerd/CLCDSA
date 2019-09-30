#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <algorithm>

using namespace std;

int n;
long long X, Y, Z, VX, VY, VZ, A, B, C, D;
double time;

int main(void) {
	freopen("b.in", "r", stdin);
	freopen("b.out", "w", stdout);
	int i, j, k, x, y, z, vx, vy, vz, t, u;

	scanf("%d", &t);
	for(u = 0; u < t; u++) {
		scanf("%d", &n);
		X = Y = Z = VX = VY = VZ = 0;
		for(i = 0; i < n; i++) {
			scanf("%d %d %d %d %d %d", &x, &y, &z, &vx, &vy, &vz);
			X += x, Y += y, Z += z, VX += vx, VY += vy, VZ += vz;
		}
		A = VX * VX + VY * VY + VZ * VZ;
		B = 2 * VX * X + 2 * VY * Y + 2 * VZ * Z;
		C = X * X + Y * Y + Z * Z;
		
		if (A == 0) {
			time = 0.0;
		}
		else {
			time = - B / (2.0 * A);
			if (time < 0.0) {
				time = 0.0;
			}
		}

		printf("Case #%d: %.8lf %.8lf\n", u+1, sqrt(A * time * time + B * time + C) / n, time);
	}

	exit(0);
}