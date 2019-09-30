#include<stdio.h>
int main(void){
	double l,x,y,s,d,time;
	scanf("%lf%lf%lf%lf%lf",&l,&x,&y,&s,&d);
	double shihan,shito,bo,timehan,timeto;
	if(s>=d){
		shihan=s-d;
		shito=l-shihan;
	}
	else //if(s<d)
	{
		shito=d-s;
		shihan=l-shito;
	}
	if(y>x){
		timehan=shihan/(y-x);
	}
	else timehan=1000000000;
	timeto=shito/(x+y);
		
	time=timeto>=timehan?timehan:timeto;
	printf("%.10f\n",time);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lf%lf%lf%lf%lf",&l,&x,&y,&s,&d);
  ^