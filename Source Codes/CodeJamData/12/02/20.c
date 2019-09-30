#include <stdlib.h>
#include <stdio.h>

int main(void)
{
	//Variables.
	int i, j, n, r, t;
	int atleast, googlers, suptrip;
	int gers[100];
	int gers2[100];
	FILE *f_in, *f_out;
	if (!(f_in = fopen("B.in", "r")))
	{
		puts("ERROR: no input file.\n");
		return EXIT_FAILURE;
	}
	f_out = fopen("B.out", "w+");
	
	fscanf(f_in, "%d\n", &n);
	for(i = 0; i < n; i++)
	{
		fprintf(f_out, "Case #%d: ", i+1);
		fscanf(f_in, "%d %d %d", &googlers, &suptrip, &atleast);
		for(j = 0; j < googlers; j++)
		{
			fscanf(f_in, "%d", &t);
			gers[j] = (t+2)/3;
			if (t == 0)
			{
				gers2[j] = 0;
			}
			else
			{
				gers2[j] = ((t+1)/3)+1;
			}
		}
		r = 0;
		for(j = 0; j < googlers; j++)
		{
			if (gers[j] >= atleast)
			{
				r++;
			}
			else
			{
				if (gers2[j] >= atleast && suptrip > 0)
				{
					suptrip--;
					r++;
				}
			}
		}
		fprintf(f_out, "%d\n", r);
	}
	fclose(f_in);
	fclose(f_out);
	return EXIT_SUCCESS;
}
