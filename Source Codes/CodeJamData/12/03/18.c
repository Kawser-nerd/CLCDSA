#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	FILE * fin = fopen("input.in", "r");
	FILE * fout = fopen("output.out", "w");
	
	int T;
	unsigned long long A, B;
	int i;
	unsigned long long j, k;
	fscanf(fin, "%d\n", &T);

	unsigned long long out;
	char ocase[40];
	char* tab;
	unsigned long long tmp;
	unsigned long long A0;
	int digi;

	for (i = 0; i < T; ++i)
	{
		fscanf(fin, "%llu ", &A);
		//printf("%llu\n", A);
		fscanf(fin, "%llu\n", &B);
		//printf("%llu\n", B);
		out = 0;
		digi = 1;
		tmp = 0;

		for (A0 = 1; A/A0 >= 10; A0 *= 10)
		{
			digi++;
		}
		//printf("%llu\n", A0);

		tab = calloc(B + 1, sizeof(char));
		for (j = A; j <= B; ++j)
		{
			if(tab[j] != 0)continue;
			tab[j] = 1;
			//printf("%llu\n", j);
			for (k = 1; k <= A0; k *= 10)
			{
				//printf("%llu\n", k);
				tmp = j / k + (j % k) * (A0 / k) * 10;
				//printf("%llu\n", tmp);
				//if(tmp < A)continue;
				//if(tmp > B)continue;
				if ((tmp >= A)&&(tmp <= B))
				{
					if (tab[tmp] == 0){
						tab[tmp] = 1;
						tab[j]++;
						//printf("%llu\n", tmp);
						//printf("%d\n", tab[tmp]);
						//printf("%d\n", tab[j]);

					}
				}
				//tab[ tmp ] == (tmp >= A)&&(tmp <= B);
				//tab[j] += (tmp >= A)&&(tmp <= B);
				//printf("%d\n", tab[tmp]);
				//printf("%llu\n", j);
			}
			out += tab[j] * (tab[j] - 1) / 2;

		}
		/*
		for (j = A; j <= B; ++j)
		{
			out += tab[j];
		}*/
		//printf("%llu\n", out);
		free(tab);

		sprintf(ocase, "Case #%d: %llu", i+1, out);
		
		if (i != T - 1)
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