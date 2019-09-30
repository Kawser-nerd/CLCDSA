#include <stdio.h>

int main() {
	int T;
	int t;
	double C, F, X;
	double P, time;
	

	scanf("%d", &T);

	for(t = 1; t <= T; t++) {
		scanf("%lf%lf%lf", &C, &F, &X);
		time = 0.0;
		P = 2.0;

		while(1) {
			if( (X - C) / P > C / F ) {
				time += C / P;
				P += F;
			}
			else {
				time += X / P;
				break;
			}

		}
	
		printf("Case #%d: %.7f\n", t, time);

	}

}
