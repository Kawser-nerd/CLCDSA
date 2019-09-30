#include<stdio.h>
#include<math.h>
#define EPS 0.0000001

int main(){
	int N;
	int case_iterator;
	scanf("%d", &N);
	for (case_iterator=0;case_iterator<N;case_iterator++){
		double f,R, t, r, g;
		scanf("%lf %lf %lf %lf %lf", &f, &R, &t, &r, &g);

		//normalizing:
		f = f/R;
		t = t/R;
		r = r/R;
		g = g/R;
		R = 1.0;

		//the problem is equilavent to the same problem with a punctual fly and 
		//strings with radius f larger (and with gaps 2f smaller)
		r = r + f;
		g = g - 2.0*f;


		if (g<=0){
			//we have a fat fly!
			printf("Case #%d: %06f\n", case_iterator+1, 1.0);
			continue;
		}

		//since we have simmety, we can calculate only a forth of the racquet
		double area = 0.0;
		double x, y;
		double R2 = (R-t-f)*(R-t-f);
		double m,n;
		y = r;
		while (y < (R-t-f)){
			n = floor((y-r)/(2.0*r+g));
			if ( ((y-r) - n*(2.0*r+g)) < g ){
				x = sqrt(R2 - y*y);
				if (x>r){
					m = floor((x-r)/(2.0*r+g));
					if ( ((x-r) - m*(2.0*r+g)) < g ){
						area += (EPS * (x - r - m*2.0*r));
					} else {
						area += (EPS * (m+1.0) * g);
					}
				}
			}
			y+=EPS;
		}

		//since probability density function is constant, the overall
		// probability is given by a proportion of areas:
		double p = 4.0*area / M_PI;

		// we have calculated the probability of the fly not hitting the racquet.
		// The probability we need is the complement:
		double P = 1.0 - p;

		printf("Case #%d: %06lf\n", case_iterator+1, P);
	}
	return 0;
}

