#include<stdio.h>

int main()
{
	int T;
	int tc;
	
	scanf("%d\n", &T);

	for (tc=1; tc<=T; tc++)
	{
		char msg[61];
		int base = 0;
		char digits[61];
		char values[62];
		int i=0;
		int j,k;
		unsigned long finalvalue = 0;
		scanf("%s", msg);
		while (msg[i])
		{
			for (j=0;j <base; j++)
				if (digits[j]==msg[i])
				{
					goto knowndigit;

				}	
			digits[base]=msg[i];
			j = base;
			base++;
knowndigit:
			if (j==0) j=1;
			else if (j==1) j=0;
			values[i] = j;
//printf("%c %d\n", msg[i], values[i]);
			i++;
		}
//printf("BASE:%d\n",base);
		if (base ==1) base=2;
		k = 0;
		while (msg[k])
		{
			finalvalue = finalvalue * base + values[k];
			k++;
		}
//		if (finalvalue == 1) finalvalue = 0;
		printf ("Case #%d: %lu\n", tc, finalvalue);
	}
}
