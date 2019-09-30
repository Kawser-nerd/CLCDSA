#include <stdio.h>
#include <string.h>
#include <math.h>
#include <gmp.h>

#ifdef DEBUG
#define ddd(s, ...) printf(s, __VA_ARGS__)
#else
#define ddd(s, ...)
#endif

double zero_to_goal(double goal, double prod) {
	return (goal / prod);
}

int main(void) {
	int t, T;

	scanf("%d", &T);
	t = 0;
	while (t<T) {
		double C, F, X;
		double prod, t_tot = 0.0f;
		int loop = 1;

		scanf("%lf %lf %lf", &C, &F, &X);

		prod = 2.0f;
		double t1 = zero_to_goal(X, prod);
		while (loop) {
			double t2 = zero_to_goal(C, prod);
			double t3 = zero_to_goal(X, prod+F);

			if (t1 < t2+t3) {
				t_tot += t1;
				loop = 0;
			} else {
				t_tot += t2;
				prod += F;
			}
			t1 = t3;
		}
		printf("Case #%d: %.7f\n", t+1, t_tot);
		t++;
	}


	return (0);
}
