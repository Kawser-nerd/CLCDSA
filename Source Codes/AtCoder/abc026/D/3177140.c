#include <stdio.h>
#include <math.h>

double A;
double B;
double C;
double eps=0.0000001;

double f(double t){
	return (A*t)+(B*sin(C*t*acos(-1.0)))-100.0;
}

int main(){

	scanf("%lf %lf %lf",&A,&B,&C);

	double l,r,mid;

	l=0;
	r=114514.0;

	int i;

	for(i=0;i<10000;i++){
		mid=(l+r)/2.0;
		if(fabs(f(mid))<=eps){
			printf("%.12f\n",mid);
			break;
		}
		if(f(mid)<0){
			l=mid;
		}
		else{
			r=mid;
		}
	}

	return 0;
} ./Main.c: In function ‘main’:
./Main.c:15:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lf %lf %lf",&A,&B,&C);
  ^