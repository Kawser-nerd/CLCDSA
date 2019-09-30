#include <stdio.h>
#include <math.h>

#define SIZE 10000

int array[SIZE] ;

void init()
{
	int i=0 ;

	for(i=0; i<SIZE; i++)
	{
		array[i] = 0 ;
	}

	return ;
}

int next_prime(int P)
{
	int not_prime = 0 ;
	int sqrt_n = 0, i=0 ;

	while(1)
	{
		not_prime = 0 ;
		sqrt_n = (int) sqrt(P) + 1;
		for(i=2; i<sqrt_n; i++)
		{
			if( (P % i) == 0)
			{
				not_prime = 1 ;
				break ;
			}
		}

		if(not_prime)
		{	
			P = P+1 ;
		}
		else
		{
			break ;
		}

	}

	return P ;
}



int main()
{
	int num_cases = 0, j=0;

	scanf("%d", &num_cases) ;
	for(j=0; j<num_cases; j++)
	{
		int x=1, A=0, B=0, P=0;
		int i=0, range=0, output=0;
		int total_marked = 0 ;

		init() ;
	
		scanf("%d %d %d", &A, &B, &P) ;

		range = B - A + 1 ;
		output = range ;
		while(1)
		{
			int count = 0 ;
			int merged = 0 ;

			P = next_prime(P) ;		
			for(i=0; i<range; i++)
			{
				if( (A+i) % P == 0)
				{
					if(array[i] == 0)
					{
						array[i] = x ;
						total_marked += 1 ;
						count++ ;
					}
					else
					{
						merged = 1 ;		
					}
				}
			}

			if(count)
			{
				output = output - count + 1 ;
				if(merged)
					output = output - 1 ;
			}

			if(total_marked == range)
				break;

			if(P >= B)
				break ;

			P = P+1 ;
		}

		printf("Case #%d: %d\n", j+1, output) ;
	}

	return 0 ;
}
