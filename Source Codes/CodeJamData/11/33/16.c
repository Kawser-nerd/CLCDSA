#include <stdlib.h>
#include <stdio.h>

#define MAX_PLAYERS 10000

int main(void)
{
	FILE *f_in, *f_out;
	if (!(f_in = fopen("C.in", "r")))
	{
		printf("ERROR: no input file.\n");
		return EXIT_FAILURE;
	}
	f_out = fopen("C.out", "w+");
	int i, j, n;
	int high, low, num;
	int players[MAX_PLAYERS];
	int f, res;
	fscanf(f_in, "%d\n", &n);
	for(i = 0; i < n; i++)
	{
		fprintf(f_out, "Case #%d: ", i+1);
		fscanf(f_in, "%d %d %d\n", &num, &low, &high);
		for(j = 0; j < num; j++)
		{
			fscanf(f_in, "%d ", &players[j]);
		}
		//Méthode bruteforce.
		printf("Players:\n");
		for(j = 0; j < num; j++)
		{
			printf("%d, ", players[j]);
		}
		printf("\n");
		res = 0;
		for(f = low; f < high+1; f++)
		{
			for(j = 0; j < num; j++)
			{
				if (res != 0)
				{
					if (res%players[j] != 0 && players[j]%res != 0)
					{
						res = 0;
						break;
					}
				}
				else
				{
					if (f%players[j] == 0 || players[j]%f == 0)
					{
						res = f;
					}
					else
					{
						break;
					}
				}
			}
			if (res != 0) break;
		}
		if (res == 0)
		{
			fprintf(f_out, "NO\n");
		}
		else
		{
			fprintf(f_out, "%d\n", res);
		}
	}
	fclose(f_in);
	fclose(f_out);
	return EXIT_SUCCESS;
}
