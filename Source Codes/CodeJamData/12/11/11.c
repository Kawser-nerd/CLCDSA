#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX (1<<17)

double v[MAX], p[MAX];

int a, b;

int main()
{
	int casos;
	int cas, i;
	double aux, menor;
	
	scanf("%d", &casos);
	
	for (cas = 1; cas <= casos; cas++)
	{
		printf("Case #%d: ", cas);
		
		scanf("%d %d", &a, &b);
		
		for (i=1; i<=a; i++)
		{
			scanf("%lf", &v[i]);
		}
		p[0] = b+2;
		aux = 1.0;
		menor = p[0];
		for (i=1; i<=a; i++)
		{
			aux = aux * (v[i]);
			p[i] = (a-i)+(b-i)+1 + (b+1)*(1-aux);
			if (p[i] < menor)
				menor = p[i];
		}
		printf("%.6f\n", menor);
	}
	
	return 0;
	
}
