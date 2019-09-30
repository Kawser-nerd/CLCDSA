#include <stdio.h>

int main()
{
	int powers_of_two[31];
	int i;
	int N, K, T, t;

	powers_of_two[0] = 1;
	for(i=1; i<=30; i++)
		powers_of_two[i] = powers_of_two[i-1]*2;

	scanf("%d", &T);

	for(t=1; t<=T; t++)
	{
		scanf("%d %d", &N, &K);
		if(K%powers_of_two[N]==powers_of_two[N]-1)
			printf("Case #%d: ON\n", t);
		else
			printf("Case #%d: OFF\n", t);
	}

	return 0;
}

