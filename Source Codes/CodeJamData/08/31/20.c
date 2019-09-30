#include <stdio.h>

//#define DEBUG1

int compneg(const void* a, const void* b);

int main(void)
{
	int N, P, K, L;
	long int freq[1000];
	long long count;
	
	int i, freqCnt, caseCnt;
	
	FILE* fin;
	
	fin = fopen("test.in", "rt");
	
	fscanf(fin, "%i", &N);
#ifdef DEBUG1
	printf("N: %i\n", N);
#endif
	
	for(caseCnt = 0; caseCnt < N; caseCnt++)
	{
		count = 0ll;
		
		fscanf(fin, "%i %i %i", &P, &K, &L);
#ifdef DEBUG1
		printf("P: %i, K: %i, L: %i\n", P, K, L);
#endif
		
		for(freqCnt= 0; freqCnt < L; freqCnt++)
			fscanf(fin, "%li", &freq[freqCnt]);
		
		qsort(freq, L, sizeof(long), compneg);
#ifdef DEBUG1
		for(freqCnt= 0; freqCnt < L; freqCnt++)
			printf("%li ", freq[freqCnt]);
		printf("\n");
#endif
		
		for(i = 0; i < L; i++)
		{
			count += (long long)(freq[i] * (i/K + 1) );
		}

		printf("Case #%i: %lli\n", caseCnt+1, count);
	}
	return 0;
}


int compneg(const void* a, const void* b)
{
	if		( *( (int*)a) > *( (int*)b) )
		return -1;
	else if	( *( (int*)a) < *( (int*)b) )
		return 1;
	else
		return 0;
}
