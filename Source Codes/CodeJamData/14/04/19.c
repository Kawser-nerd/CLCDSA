#include <stdio.h>
#include <stdlib.h>

int comp(const void *a, const void *b)
{
	double *x = (double *) a;
	double *y = (double *) b;
	if (*x < *y) return -1;
	else 
	{
		if (*x > *y) return 1; 
		else return 0;
	}
}
	
int main()
{
	int i, j, k, t, n, max, score;
	double nao[1000];
	double ken[1000];

	scanf("%d", &t);
	for(k=0; k<t; k++)
	{
		scanf("%d", &n);
		for(j=0; j<n; j++)
			scanf("%lf", &nao[j]);
		for(j=0; j<n; j++)
			scanf("%lf", &ken[j]);

		qsort(nao, n, sizeof(double), comp);
		qsort(ken, n, sizeof(double), comp);

		//for(i=0; i<n; i++) printf("%lf ", nao[i]); printf("\n");
		//for(i=0; i<n; i++) printf("%lf ", ken[i]); printf("\n");

		printf("Case #%d: ", k+1);
		i=0; j=0; score=0; max=n;
		while(i<n)
		{
			while(i<n && nao[i]<ken[j]) {i++; max--;}
			while(i<n && j<max && nao[i]>ken[j]) {i++; j++; score++;}
		}
		printf("%d ", score);

		score=0;
		for(i=0; i<n; i++)
		{
			j=0;
			while(j<n && nao[i]>ken[j]) j++;

			nao[i]=0;
			if(j>=n)
				score++;
			else
				ken[j]=0;
		}
		printf("%d\n", score);

	}

	return 0;
}
