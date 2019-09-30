/* 2014.4.12 Yoshi-TS4 */

#include <stdio.h>
#include <vector>
#include <algorithm>

std::vector<double> p1, p2;

int main()
{
	FILE* fin = fopen("input.txt", "r");
	FILE* fout = fopen("output.txt", "w");

	int T;

	fscanf(fin, "%d", &T);

	for (int c_n = 1; c_n <= T; c_n++)
	{
		int N;

		fscanf(fin, "%d", &N);

		p1.clear();
		p2.clear();

		for (int i = 0; i < N; i++)
		{
			double d;
			fscanf(fin, "%lf", &d);
			p1.push_back(d);
		}
		for (int i = 0; i < N; i++)
		{
			double d;
			fscanf(fin, "%lf", &d);
			p2.push_back(d);
		}
		std::sort(p1.begin(), p1.end());
		std::sort(p2.begin(), p2.end());

		int R1=0, R2=0;
		int pointer = 0;
		for (int i = 0; i < N; i++)
		{
			if(p1[i] > p2[pointer])
			{
				pointer++;
				R1++;
			}
		}
		int j = -1;
		for (int i = 0; i < N; i++)
		{
			bool ended = true;
			while (j < N - 1)
			{
				j++;
				if (p2[j] > p1[i])
				{
					ended = false;
					break;
				}
			}
			if (ended)
			{
				R2 = N - i;
				break;
			}
		}

		fprintf(fout, "Case #%d: %d %d\n", c_n, R1, R2);
	}

	return -0;
}