#include <stdio.h>
#include <stdlib.h>

int gcd(int m, int n)
{
	if(m==0)
		return n;
	if(n==0)
		return m;
	if(m%n==0)
		return n;
	return gcd(n, m%n);
}

int main()
{
	int C, c;
	int N;
	int t1, t2, t3;
	int g;
	int ans;

	scanf("%d", &C);
	for(c=1; c<=C; c++)
	{
		scanf("%d", &N);
		if(N==2)
		{
			scanf("%d %d", &t1, &t2);
			g = abs(t1-t2);
			ans = (g-t1%g)%g;
			if((g-t2%g)%g<ans)
				ans = (g-t2%g)%g;
		}
		else
		{
			scanf("%d %d %d", &t1, &t2, &t3);
			g = gcd(abs(t1-t2), abs(t2-t3));
			ans = g+1;
			if((g-t1%g)%g<ans)
				ans = (g-t1%g)%g;
			if((g-t2%g)%g<ans)
				ans = (g-t2%g)%g;
			if((g-t3%g)%g<ans)
				ans = (g-t3%g)%g;
		}
		printf("Case #%d: %d\n", c, ans);
	}

	return 0;
}

