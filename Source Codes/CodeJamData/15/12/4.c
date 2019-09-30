#include <stdio.h>

int M[100000];
int N, T, B, A;
long long H, L, D, num, nump;

int main()
{
	FILE *input, *output;
	int a, i, j;
	char c;
	
	input = fopen("barber.in", "r");
	output = fopen("barber.out", "w");
	
	fscanf(input, "%d\n", &T);
	
	for(a=1; a<=T; a++)
	{
		fscanf(input, "%d %d\n", &B, &N);
		
		for(i=0; i<B; i++)
			fscanf(input, "%d%c", M+i, &c);
		
		H = (long long) M[0]*N;
		L = 0;
		
		while(H > L+2)
		{
			D = (H+L)/2;
			
			for(i=0, num=0; i<B; i++)
			{
				num += (D+M[i])/M[i];
			}
			
			if(num < N)
				L = D;
			else
				H = D;
		}
		
		for(j=-1; j<=3; j++)
		{
			D = L+ (long long) j;
			
			for(i=0, num=0; i<B; i++)
			{
				num += (D+M[i])/M[i];
			}
			
			if(num >= N)
				break;
			nump = num;
		}
		
		for(i=0; i<B; i++)
		{
			if(D%M[i] == 0)
				N--;
			if(N == nump)
			{
				A = i+1;
				break;
			}
		}
		
		fprintf(output, "Case #%d: %d\n", a, A);
	}
	
	return 0;
}