#include <stdio.h>
#include <gmp.h>
#include <stdlib.h>
#include <string.h>
// gcc -std=gnu99 xxx.c -o xxx.exe [-lgmp]

int Imax(int,int);
long Lmax(long,long);
long Lmin(long,long);
/*------------------------------------------------------------------------------------------*/

void main()
{
	freopen("B-large.in", "r", stdin);
	freopen("B-largeout.txt", "w", stdout);
	
	int T;
	//read number of test cases
	scanf("%d", &T);
	for (int ith=1; ith<=T; ith++)
	{
		// variables
		long A, B, K;
		long i,j;
		long long combs;
		scanf("%ld%ld%ld", &A, &B, &K);
		combs = 0;
		
		long numMax, numMin;
		numMax = Lmax(A,B);
		numMin = Lmin(A,B);
		
		for (i=0;i<numMin;i++)
		{
			if (i<K) combs+=numMax;
			else 
			{
				combs+=K;
				for(j=K;j<numMax;j++)
				{
					if ((i&j)<K) combs++;
				}
			}
		}
		
		printf("Case #%ld: %I64d\n", ith, combs);
	}
	
	fclose(stdin);
	fclose(stdout);
	
}


/*-------------------------------------------------------------------------------------------------------*/
/*
	write helper functions here
*/
int Imax(int a, int b)
{
	if (a>b)  return a;
	return b;
}

long Lmax(long a, long b)
{
	if (a>b) return a;
	return b;
}
long Lmin(long a, long b)
{
	if (a<b) return a;
	return b;
}


