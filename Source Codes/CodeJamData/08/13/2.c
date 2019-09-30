#include <stdio.h>

int a,b,c,d;

void powah(int z)
{
	if (z == 0)
	{
		a = d = 1;
		b = c = 0;
		return;
	}
	powah(z/2);
	int aa = (a*a+b*c+10000000)%1000;
	int bb = (a*b+b*d+10000000)%1000;
	int cc = (a*c+c*d+10000000)%1000;
	int dd = (d*d+b*c+10000000)%1000;
	a = aa;
	b = bb;
	c = cc;
	d = dd;

	if (z & 1)
	{
		aa = (6*a + b+10000)%1000;
		bb = (-4*a+10000)%1000;
		cc = (6*c + d+10000)%1000;
		dd = (-4*c+10000)%1000;
		a = aa; b = bb; c = cc; d = dd;
	}
}

int main()
{
	int t;
	scanf("%d", &t);
	for (int cc = 1; cc <= t; cc++)
	{
		int n;
		scanf("%d", &n);
		powah(n);
		printf("Case #%d: %03d\n", cc, (6*c+2*d+99999)%1000);
	}
	return 0;
}
