#include <stdio.h>

#define LLMAX 9223372036854775807LL;

int C, D;
int pos[200];
int V[200];

int isDoable(long long k)
{
	long long next;
	int i;
	
	if (D*(V[0]-1) > 2*k)
		return 0;
	
	next = pos[0]-k+D*V[0];
	
	for (i=1; i<C; i++)
	{
		if (next < pos[i]-k)
			next = pos[i]-k;
		
		if (next + (V[i]-1)*D > pos[i]+k)
		{
			//fprintf(stderr, "DONT %d\n", i);
			return 0;
		}
		
		next += V[i]*D;
	}
	
	//fprintf(stderr, "DO\n");
	
	return 1;
}

void solveCase()
{
	long long low, high;
	long long mid;
	int i;
	
	low = 0;
	high = LLMAX;
	
	scanf("%d %d", &C, &D);
	D*=2;
	
	for (i=0; i<C; i++)
	{
		scanf("%d %d", &pos[i], &V[i]);
		pos[i] *=2;
	}
	
	if (isDoable(0))
	{
		printf("0.0\n");
		return;
	}
	
	while (high-low > 1)
	{
		mid = low + (high-low)/2;
		
		//fprintf(stderr, "%lld\n", mid);
		if (isDoable(mid))
			high = mid;
		else
			low = mid;
	}
	
	if (high & 1)
		printf("%lld.5\n", high/2);
	else
		printf("%lld.0\n", high/2);
}

int main()
{
	int i,T;
	
	scanf("%d", &T);
	
	for (i=0; i<T; i++)
	{
		printf("Case #%d: ", i+1);
		solveCase();
	}
	
	return 0;
}
