#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	FILE * fin = fopen("input.in", "r");
	FILE * fout = fopen("output.out", "w");
	
	int T, N, S, p, t[110];
	int i, j;
	fscanf(fin, "%d\n", &T);

	char in[400];
	int out;
	char ocase[20];

	int n3p43p3, n3p2;
	//int n2930, n01, nunclear, n3p43p3, n3p4, n3p2, n3p1, n3p3;
	// n2930 the # of 29 and 30, n01 the # of 0 and 1
	//

	for (i = 0; i < T; ++i)
	{
		fscanf(fin, "%d ", &N);
		fscanf(fin, "%d ", &S);
		fscanf(fin, "%d", &p);

		n3p2 = 0;
		n3p43p3 = 0;

		for (j = 0; j < N - 1; ++j)
		{
			fscanf(fin, " %d", &(t[j]));
		}
		if (i != T - 1)
			fscanf(fin, " %d\n", &(t[j]));
		else
			fscanf(fin, " %d", &(t[j]));

		for (j = 0; j < N; ++j)
		{
			//printf("%d\n", t[j]);
			if (t[j] >= (3*p - 2))
				n3p2++;
			if (p == 1)
			{
				n3p43p3 = 0;
			}
			else if ((t[j] == (3*p - 4)) || (t[j] == (3*p - 3)))
				n3p43p3++;
		}
		//printf("%d\n", n3p43p3);
		//printf("%d\n", n3p2);

		if (S < n3p43p3)
			out = S + n3p2;
		else if (S >= n3p43p3)
			out = n3p43p3 + n3p2;

		//memset(ocase, 0, 20);
		//memset(in, 0, 120);
		//memset(out, 0, 120);
		sprintf(ocase, "Case #%d: %d", i+1, out);
		//strcpy(out, ocase);
		
		if (i != T -1)
		{
			fprintf (fout, "%s\n", ocase);
		}
		else
			fprintf (fout, "%s", ocase);
	}

	fclose(fin);
	fclose(fout);


	return 0;
}