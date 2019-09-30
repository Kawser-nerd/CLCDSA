#include <stdio.h>

unsigned int m[1024];
unsigned int price[10][1023];
int p;

unsigned int track(int s, int b)
{
	if (b == 0)
	{
		if (m[s] >= p)
			return 0;
		else
			return 1500000000;
	}

	unsigned int act1 = track(s, b-1) + track(s+(1<<(b-1)), b-1);
	for (int i=s; i<s+(1<<b); i++)
		m[i]++;
	unsigned int act2 = price[b][s>>b] + track(s, b-1) + track(s+(1<<(b-1)), b-1);
	for (int i=s; i<s+(1<<b); i++)
		m[i]--;
	return act1<act2 ? act1 : act2;
}

int main()
{
	int t;
	scanf("%d", &t);
	for (int c=1; c<=t; c++)
	{
		scanf("%d", &p);
		for (int i=0; (i>>p) == 0; i++)
			scanf("%d", &m[i]);
		for (int b=1; b<=p; b++)
		{
			for (int i=0; (i>>(p-b)) == 0; i++)
				scanf("%d", &price[b][i]);
		}

		printf("Case #%d: %d\n", c, track(0,p));
	}
}
