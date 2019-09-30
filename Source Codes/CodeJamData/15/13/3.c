#include <stdio.h>

int T, N;
double X[5000], Y[5000];
int M[5000];

int main()
{
	FILE *input, *output;
	int a, i, j, k, n1, n2;
	double m;
	
	input = fopen("logging.in", "r");
	output = fopen("logging.out", "w");
	
	fscanf(input, "%d\n", &T);
	
	for(a=1; a<=T; a++)
	{
		fscanf(input, "%d\n", &N);
		
		for(i=0; i<N; i++)
		{
			M[i] = N-3;
			if(M[i] < 0)
				M[i] = 0;
			fscanf(input, "%lf %lf\n", X+i, Y+i);
		}
			
		for(i=0; i<N; i++)
		{
			for(j=i+1; j<N; j++)
			{
				m = (Y[i]-Y[j])/(X[i]-X[j]);
				for(k=0, n1=0, n2=0; k<N; k++)
				{
					if(Y[k]-Y[j] >= m*(X[k]-X[j])-1e-9)
						n1++;
					if(Y[k]-Y[j] <= m*(X[k]-X[j])+1e-9)
						n2++;
					if((Y[k]-Y[j] >= m*(X[k]-X[j])-1e-9) && (Y[k]-Y[j] <= m*(X[k]-X[j])+1e-9))
					{
						n1--;
						n2--;
					}
				}
				
				if(n1 < n2)
					n2 = n1;
				if(n2 < M[i])
					M[i] = n2;
				if(n2 < M[j])
					M[j] = n2;
			}
		}
		
		fprintf(output, "Case #%d:\n", a);
		for(i=0; i<N; i++)
			fprintf(output, "%d\n", M[i]);
	}
}