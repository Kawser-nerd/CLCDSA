#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	double l,x,y,s,d,tp,tn,tmin;

	scanf("%lf %lf %lf %lf %lf" ,&l,&x,&y,&s,&d);

	if(x<y)
	{
		if(s>d)
		{
		tp=(l-(s-d))/(x+y);
		tn=(s-d)/(y-x);
		}
		else
		{
		tp=(d-s)/(x+y);
		tn=(l-(d-s))/(y-x);
		}
			if(tp<tn)
				tmin=tp;
			else
				tmin=tn;
	}
	else if(x>y)
	{
		if(s>d)
		{
		tp=(l-(s-d))/(x+y);
		tn=(l-(s-d))/(x-y);
		}
		else
		{
		tp=(d-s)/(x+y);
		tn=(d-s)/(x-y);
		}
			if(tp<tn)
				tmin=tp;
			else
				tmin=tn;
	}
	else
	{
		if(s>d)
		{
		tmin=(l-(s-d))/(x+y);
		}
		else
		{
		tmin=(d-s)/(x+y);
		}
	}
	printf("%f\n" ,tmin);
return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lf %lf %lf %lf %lf" ,&l,&x,&y,&s,&d);
  ^