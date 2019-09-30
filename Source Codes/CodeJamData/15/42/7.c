#include <stdio.h>

double R[200];
double C[200];

int main()
{
    FILE *input, *output;
    int a;
    int T, N, i;
	double V, X, x, y;
    char c;
     
    input = fopen("kiddiepool.in", "r");
    output = fopen("kiddiepool.out", "w");
     
    fscanf(input, "%d\n",&T);
     
    for(a=0; a<T; a++)
    {
        fscanf(input, "%d %lf %lf\n", &N, &V, &X);
         
        for(i=0; i<N; i++)
			fscanf(input, "%lf %lf\n", R+i, C+i);
		
		if(N == 1)
		{
			if(C[0] == X)
				fprintf(output, "Case #%d: %lf\n", (a+1), V/R[0]);
			else
				fprintf(output, "Case #%d: IMPOSSIBLE\n", (a+1));
			continue;
		}
		
		C[0] -= X;
		C[1] -= X;
		
		if(C[0]*C[1] > 0)
		{
			fprintf(output, "Case #%d: IMPOSSIBLE\n", (a+1));
			continue;
		}
		
		if(C[0] == 0 && C[1] == 0)
		{
			fprintf(output, "Case #%d: %lf\n", (a+1), V/(R[0]+R[1]));
			continue;
		}
		
		x = -1*C[1]/(C[0]-C[1]);
		y = C[0]/(C[0]-C[1]);
		x *= V;
		y *= V;
		
		if(x/R[0] < y/R[1])
			fprintf(output, "Case #%d: %lf\n", (a+1), y/R[1]);
		else
			fprintf(output, "Case #%d: %lf\n", (a+1), x/R[0]);
    }
     
    return 0;
}