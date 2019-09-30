#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
	long long int *aux = (long long int *) a;
	long long int *aux2 = (long long int *) b;
	
	if ((*aux) < (*aux2) ) {
		return -1;	
	} else {
		return 1;
	}
}

int main()
{
	long long int i, j, k, l, m, n, o, p, t;
	long long int *vet2;
	long long int *vet3;
	char *vet;
	vet2 = (long long int *) malloc(sizeof(long long int) * 1000005);
	vet3 = (long long int *) malloc(sizeof(long long int) * 100000005);
	vet = (char *) malloc(sizeof(char) * 1000005);

	for(i = 3; i < 1000005; i = i + 2)
	{
		vet[i] = '1';	
		vet[i+1] = '0';
	}
	
	vet[1] = '0';
	vet[2] = '1';
		
	for(i = 3; i < 1100; i++)
	{
		if(vet[i] == '1')
		{
			for(j = 3*i; j < 1000005; j = j + i)
			{
				vet[j] = '0';	
			}	
		} 	
	}
	
	p = 0;
	
	for(i = 1; i < 1000005; i++)
	{
		if(vet[i] == '1')
		{
			vet2[p] = i;
			p++;	
		}	
	}
	k = 0;
	for (i = 0; i < p; i++) {
		j = 1000000;
		l = vet2[i] * vet2[i];
		while (l <= j*j) {
			vet3[k] = l;
			l = l * vet2[i];
			k++;	
		}	
	}
	
	qsort(vet3, k, sizeof(long long int), cmp);
	scanf("%I64d", &t);
	for (o = 1; o <= t; o++) {
		scanf("%I64d", &n);
		
		for (i = 0; i < k; i++) {
			if (vet3[i] > n) {
				break;	
			}	
		}
		if (n == 1) {
			printf("Case #%I64d: 0\n", o);	
		} else {
			printf("Case #%I64d: %I64d\n", o, i+1);
		}
	}
	
	return 0;	
}
