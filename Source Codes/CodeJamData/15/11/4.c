#include <stdio.h>

int M[100000];
int N, T, A1, A2;

int main()
{
	FILE *input, *output;
	int a, i, m;
	char c;
	
	input = fopen("mushroom.in", "r");
	output = fopen("mushroom.out", "w");
	
	fscanf(input, "%d\n", &T);
	
	for(a=1; a<=T; a++)
	{
		fscanf(input, "%d\n", &N);
		
		for(i=0, A1=0, A2=0; i<N; i++)
			fscanf(input, "%d%c", M+i, &c);
		
		for(i=1, m=0; i<N; i++)
		{
			if(M[i-1] > M[i])
				A1 += M[i-1]-M[i];
			if(M[i-1]-M[i] > m)
				m = M[i-1]-M[i];
		}
		
		for(i=0; i<N-1 && m>0; i++)
		{
			if(M[i] >= m)
				A2 += m;
			else
				A2 += M[i];
		}
		
		fprintf(output, "Case #%d: %d %d\n", a, A1, A2);
	}
	
	return 0;
}