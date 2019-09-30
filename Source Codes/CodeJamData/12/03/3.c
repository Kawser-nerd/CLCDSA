#include <stdio.h>
#include <stdlib.h>

void next(int chif[7], int digit)
{
	int k;
	for(k = 0; k < digit; k++)
	{
		if(chif[k] < 9)
		{
			chif[k] = chif[k] + 1;
			k = digit;
		}
		else chif[k] = 0;
	}
}

int combien(int chif[7], int digit, int n, int B)
{
	int k, chif2[7], l, number, puis, cmb = 0, dejapris[7];
	for(k = 1; k < digit; k++) // On coupe à l'endroit k
	{
		for(l = 0; l < digit; l++)
		{
			chif2[(l+k)%digit] = chif[l];
		}
		puis = 1;
		number = 0;
		for(l = 0; l < digit; l++)
		{
			number += chif2[l]*puis;
			puis *= 10;
		}
		if(number > n && number <= B)
		{
			for(l = 0; l < cmb; l++)
			{
				if(number == dejapris[l]) l = 27;
			}
			if(l < 27)
			{
				dejapris[cmb] = number;
				cmb++;
			}

		}
	}
	return cmb;
}

int main()
{
	int A, B, n, i, T, digit, total, chif[7], j, k;
	
	scanf("%d", &T);
	for(i = 0; i < T; i++)
	{
		total = 0;
		scanf("%d %d", &A, &B);
		if(A < 10) digit = 1;
		else if(A < 100) digit = 2;
		else if(A < 1000) digit = 3;
		else if(A < 10000) digit = 4;
		else if(A < 100000) digit = 5;
		else if(A < 1000000) digit = 6;
		else digit = 7;
		j = A;
		for(k = 0; k < digit; k++)
		{
			chif[k] = j%10;
			j = (j-chif[k])/10;
		}
		for(n = A; n < B; n++)
		{
			total += combien(chif, digit, n, B);
			next(chif, digit);
		}
		printf("Case #%d: %d\n", i+1, total);
	}
	return 0;
}
