#include <stdio.h>
#include <stdlib.h>
#define A_DEP 1
#define A_ARR 2
#define B_DEP 3
#define B_ARR 4

void sort(int*, int*, int);

int main(void)
{
	int i, j;
	int depH, depM, arrH, arrM;
	int stockA, stockB;
	int sA, sB;

	int N, T, NA, NB;
	int *time, *type;

	scanf("%d", &N);

	for (i = 0; i < N; ++i)
	{
		sA = sB = 0;
		stockA = stockB = 0;

		scanf("%d", &T);
		scanf("%d %d", &NA, &NB);

		time = malloc((NA + NB) * 2 * sizeof(int));
		type = malloc((NA + NB) * 2 * sizeof(int));

		for (j = 0; j < NA; ++j)
		{
			scanf("%d:%d %d:%d", &depH, &depM, &arrH, &arrM);
			time[2*j] = 60 * depH + depM;
			type[2*j] = A_DEP;
			time[2*j+1] = 60 * arrH + arrM + T;
			type[2*j+1] = B_ARR;
		}
		for (; j < NA + NB; ++j)
		{
			scanf("%d:%d %d:%d", &depH, &depM, &arrH, &arrM);
			time[2*j] = 60 * depH + depM;
			type[2*j] = B_DEP;
			time[2*j+1] = 60 * arrH + arrM + T;
			type[2*j+1] = A_ARR;
		}

		sort(time, type, (NA + NB) * 2);

		for (j = 0; j < (NA + NB) * 2; ++j)
		{
			switch (type[j])
			{
			case A_DEP:
				if (stockA == 0)
				{
					++sA;
				}
				else
				{
					--stockA;
				}
				break;
			case A_ARR:
				++stockA;
				break;
			case B_DEP:
				if (stockB == 0)
				{
					++sB;
				}
				else
				{
					--stockB;
				}
				break;
			case B_ARR:
				++stockB;
				break;
			}
		}

		printf("Case #%d: %d %d\n", i + 1, sA, sB);

		free(time);
		free(type);
	}

	return 0;
}

void sort(int* time, int* type, int n)
{
	int i, j;
	int temp;

	// bubble sort
	for (i = n - 1; i > 0; --i)
	{
		for (j = 0; j < i; ++j)
		{
			if ((time[j] > time[j+1])
				|| (time[j] == time[j+1] 
					&& (type[j+1] == A_ARR || type[j+1] == B_ARR)
				   )
			   )
			{
				temp = time[j];
				time[j] = time[j+1];
				time[j+1] = temp;
				temp = type[j];
				type[j] = type[j+1];
				type[j+1] = temp;
			}
		}
	}

	return;
}
