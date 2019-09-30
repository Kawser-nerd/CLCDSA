#include <stdio.h>
#include <math.h>

double f(double x, double P){
	return x + P * pow(2, -x / 1.5);
}

int main(){
	int i;
	double P;
	scanf("%lf", &P);
	double l = 0, r = 1e18, h1, h2;
	for(i = 0; i < 1000; i++){
//		printf("i = %d\n", i);
//		printf("(l, r) = (%lf, %lf)\n", l, r);
		h1 = (r + 2 * l) / 3;
		h2 = (2 * r + l) / 3;
		if(f(h1, P) > f(h2, P)){
			l = h1;
		}
		else{
			r = h2;
		}
	}
	printf("%.10lf\n", f((l + r) / 2, P));
} ./Main.c: In function ‘main’:
./Main.c:11:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lf", &P);
  ^