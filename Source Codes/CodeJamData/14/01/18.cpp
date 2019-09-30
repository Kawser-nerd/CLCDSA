/* 2014.4.12 Yoshi-TS4 */

#include <stdio.h>
#include <Windows.h>

int main()
{
	FILE* fin = fopen("input.txt", "r");
	FILE* fout = fopen("output.txt", "w");

	int T;
	int a[4], b[4], c[4];

	fscanf(fin, "%d", &T);

	for (int c_n = 1; c_n <= T; c_n++)
	{
		int n, k;
		int cnt = 0;

		fscanf(fin, "%d", &n);

		for (int i = 1; i <= 4; i++)
			for (int j = 0; j < 4; j++)
			{
				fscanf(fin, "%d", &k);
				if (i == n)
					a[j] = k;
			}

		fscanf(fin, "%d", &n);
		for (int i = 1; i <= 4; i++)
			for (int j = 0; j < 4; j++)
			{
				fscanf(fin, "%d", &k);
				if (i == n)
					b[j] = k;
			}

		for (int i = 0; i < 4; i++)
		{
			bool result = false;
			for (int j = 0; j < 4; j++)
			{
				if (b[j] == a[i]) result = true;
			}
			if (result)
				c[cnt++] = a[i];
		}

		if (cnt == 1)
			fprintf(fout, "Case #%d: %lld\n", c_n, c[0]);
		else if (cnt == 0)
			fprintf(fout, "Case #%d: Volunteer cheated!\n", c_n);
		else fprintf(fout, "Case #%d: Bad magician!\n", c_n);
	}

	return -0;
}
