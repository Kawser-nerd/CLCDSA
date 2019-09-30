#include<stdio.h>
#include<math.h>
#define PI 3.1415926535897932384626433832795

int main(void){
	double a,b,c,s,f,jud,x;
	scanf("%lf%lf%lf",&a,&b,&c);
	s = 0;f = 10000;
	while(f-s >= 0.000000000001){
		jud = (s+f)/2;
		x = a*jud+b*sin(c*jud*PI);
		if(x < 100){s = jud;}
		else{f = jud;}
	}
	printf("%.12lf",(s+f)/2);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lf%lf%lf",&a,&b,&c);
  ^