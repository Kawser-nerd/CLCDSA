#include<stdio.h>

int main()
{
	freopen("gcj3.in", "r", stdin);
	freopen("gcj3.out", "w", stdout);
	int ca, count;
	scanf("%d", &ca);
	for (count = 1; count <= ca; count++)
	{
		int n;
		scanf("%d",&n);
		unsigned long min=1000001;
		unsigned long ans=0;
		unsigned long now;
		unsigned long sum=0;
		while (n--)
		{
			scanf("%d",&now);
			ans=ans^now;
			if (min>now) min=now;
			sum+=now;
		}
		printf("Case #%d: ",count);
		if (ans!=0)
			printf("NO");
		else
			printf("%d",sum-min);
		printf("\n");
	}
	return 0;
}
