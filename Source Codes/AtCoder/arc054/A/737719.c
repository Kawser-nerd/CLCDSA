#include <stdio.h>
#include <math.h>
 
int main(void) {
	int i, j;
	double l, x, y, s, d, d1, d2, k, ak, bk;
	scanf("%lf %lf %lf %lf %lf", &l, &x, &y, &s, &d);
	if(d==s){printf("0.000000\n");return 0;}
	if(d > s){
		d1 = d-s;
		d2 = s + l - d;
	}
	else{
		d1 = d + l - s;
		d2 = s - d;
	}
	ak = d1/(x+y);
	if(y-x > 0){
		bk = d2/(y-x);
		if(ak>bk){printf("%lf",  bk);return 0;}
	}
	printf("%lf", ak);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lf %lf %lf %lf %lf", &l, &x, &y, &s, &d);
  ^