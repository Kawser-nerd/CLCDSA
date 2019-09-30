#include<stdio.h>

int main(void)
{
	long double l,x,y,s,d,ans1,ans2,ans;
	scanf("%Lf %Lf %Lf %Lf %Lf",&l,&x,&y,&s,&d);
	if(d==s)
	{
		printf("%10.10Lf\n",(long double)0.0);
		return 0;
	}
	if(d - s > 0)
	{
		ans1=(d-s)/(y+x);
		if(y-x>0)
		{
			ans2=(l-d+s)/(y-x);
		}
		else
		{
			ans2=(d-s)/(x-y);
		}
	}
	else
	{
		ans2=(l-s+d)/(y+x);
		if(y-x>0)
		{
			ans1=(s-d)/(y-x);
		}
		else
		{
			ans1=(l-s+d)/(x-y);
		}
	}
	ans=(ans1<ans2)?ans1:ans2;
	printf("%10.10Lf\n",ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%Lf %Lf %Lf %Lf %Lf",&l,&x,&y,&s,&d);
  ^