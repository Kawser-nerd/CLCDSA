#include <stdio.h>

int main(){
	double n,m,fn,fm,cc,ce;
	scanf("%lf %lf",&n,&m);
	if(n >= 12)
		n = n - 12;
	fn = n * 30 + m / 2;
	fm = m * 6;
	cc = fn - fm;
	ce = fm - fn;

	if(cc < 0)
		cc = cc * -1;
	if(ce < 0)
		ce = ce * -1; 


	if(cc >= ce){
	if(ce > 180)
		printf("%.4f",360 - ce);
	else
		printf("%.4f",ce);
	}
	else{
	if(cc > 180)
		printf("%.4f",360 - cc);
	else
		printf("%.4f",cc);
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lf %lf",&n,&m);
  ^