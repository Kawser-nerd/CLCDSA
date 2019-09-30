/* 2014.4.12 Yoshi-TS4 */

#include <stdio.h>

int main()
{
	FILE* fin = fopen("input.txt", "r");
	FILE* fout = fopen("output.txt", "w");

	int T;

	fscanf(fin, "%d", &T);

	for (int c_n = 1; c_n <= T; c_n++)
	{
		double C, F, X;

		fscanf(fin, "%lf%lf%lf", &C, &F, &X);

		double prep = 0;
		double result = X / 2.0;
		for (int i = 1;; i++)
		{
			double n_prep = prep + C / (2.0 + F * (i - 1));
			double n_result = n_prep + X / (2.0 + F * i);
			if (n_result >= result) break;
			prep = n_prep;
			result = n_result;
		}

		fprintf(fout, "Case #%d: %.8f\n", c_n, result);
	}

	return -0;
}