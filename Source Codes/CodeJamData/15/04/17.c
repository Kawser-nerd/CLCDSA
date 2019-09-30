#include <stdio.h>

int main()
{
	int t,T,X,R,C,min,max;
	scanf("%d", &T);

	for(t=1;t<=T;t++)
	{
		scanf("%d%d%d", &X, &R, &C);

		min = (R<C)?R:C;
		max = (R>C)?R:C;

		if (X>6 || X>max || X>2*min || (R*C)%X!=0)
		{
			printf("Case #%d: RICHARD\n", t);
			continue;
		}

		if (X<4 || X<=min)
		{
			printf("Case #%d: GABRIEL\n", t);
			continue;
		}

		if (X==4 && min==2)
		{
			printf("Case #%d: RICHARD\n", t);
			continue;
		}

		if (X==4 && min==3)
		{
			printf("Case #%d: GABRIEL\n", t);
			continue;
		}

		if (X==5 && min==3)
		{
			if (max==5)
			{
				printf("Case #%d: RICHARD\n", t);
			}
			else
			{
				printf("Case #%d: GABRIEL\n", t);
			}
			continue;
		}

		if (X==5 && min==4)
		{
			printf("Case #%d: GABRIEL\n", t);
			continue;
		}
	
		if (X==6 && min==3)
		{
			printf("Case #%d: RICHARD\n", t);
			continue;
		}

		if (X==6)
		{
			printf("Case #%d: GABRIEL\n", t);
			continue;
		}

		return -1;
	}

	return 0;
}
