
#include <stdio.h>
#include <stdlib.h>

#define MAX 1000000
int count[MAX];

int swap(int a) {
	int res = 0;
	while (a) {
		res *= 10;
		res += a%10;
		a /= 10;
	}
	
	return res;
}

int 
main(int argc, char **argv)
{
	count[1] = 1;
	for (int i = 2; i <= MAX; i++)
	{
		int swapped = swap(i);
		
		
		if (swap(swapped) != i || swapped >= i) {
			
			count[i] = count[i-1] + 1;			
			continue;
		}
		
		int pred = count[i-1];
		int swap = count[swapped];
		
		count[i] = 1 + (pred < swap ? pred : swap);		
	}

	int casesTotal;	
	scanf("%d", &casesTotal);

	
	int n;
	
	for(int caseNo = 1; caseNo <= casesTotal; caseNo++)
	{

		scanf("%d", &n);
		
		

	
	
		printf("Case #%d: %d\n", caseNo, count[n]);
	}
}