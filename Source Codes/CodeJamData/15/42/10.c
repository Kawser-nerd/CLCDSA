#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void do_test(int t)
{
	int n;
	double v, x;
	double cold_temp = 0.0;
	double cold_flow = 0.0;
	double hot_temp = 0.0;
	double hot_flow = 0.0;
	double equal_flow = 0.0;
	int i;

	scanf(" %d %lf %lf", &n, &v, &x);

	for (i = 0; i < n; i++)
	{
		double r, c;

		scanf(" %lf %lf", &r, &c);

		if (c < x - 10e-6)
		{
			cold_temp += r * c;
			cold_flow += r;
		}
		else if (c > x + 10e-6)
		{
			hot_temp += r * c;
			hot_flow += r;
		}
		else
		{
			equal_flow += r;
		}
	}

	if (cold_flow > 0 && hot_flow > 0)
	{
		double r1, c1, c2;
		cold_temp /= cold_flow;
		hot_temp /= hot_flow;

		if ((cold_flow * (x - cold_temp)) > (hot_flow * (hot_temp - x)))
		{
			r1 = hot_flow;
			c1 = hot_temp;
			c2 = cold_temp;
		}
		else
		{
			r1 = cold_flow;
			c1 = cold_temp;
			c2 = hot_temp;
		}
		
		equal_flow += r1 * (1 - (c1 - x)/(c2 - x));
	}

	if (equal_flow > 0)
		printf("Case #%d: %.9f\n", t + 1, v / equal_flow);
	else
		printf("Case #%d: IMPOSSIBLE\n", t + 1);
}

int main()
{
	int t, i;

	scanf("%d", &t);
	
	for (i = 0; i < t; i++)
		do_test(i);

	return 0;
}
