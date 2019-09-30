#include <stdio.h>
#include <math.h>

int x[4], y[4], r[4];

double dist(int i, int j)
{
	return sqrt((x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]));
}

double mmax(double a, double b)
{
	return a<b ? b : a;
}

int main(void)
{
	int N, C, test, i, j;
	double ans;
	
	scanf("%d", &C);
	for(test = 1; test <= C; ++test)
	{
		scanf("%d", &N);
		for(i = 0; i < N; i++)
		{
			scanf("%d %d %d", &x[i], &y[i], &r[i]);
		}
		if(N==3)
		{
			ans = mmax((dist(0, 1)+r[0]+r[1])*0.5, r[2]);
			if(mmax((dist(0, 2)+r[0]+r[2])*0.5, r[1]) < ans)
			{
				ans = mmax((dist(0, 2)+r[0]+r[2])*0.5, r[1]);
			}
			if(mmax((dist(1, 2)+r[1]+r[2])*0.5, r[0]) < ans)
			{
				ans = mmax((dist(1, 2)+r[1]+r[2])*0.5, r[0]);
			}
		}
		else
		{
			ans = 0;
			for(j = 0; j < N; j++)
			{
				if(r[j] > ans)
				{
					ans=r[j];
				}
			}
		}
		printf("Case #%d: %.6lf\n", test, ans);
	}
	
	return 0;
}
