#include <stdlib.h>
#include <stdio.h>

int main(void)
{
	char trad[26] = {'y', 'h', 'e', 's', 'o', 'c', 'v', 'x', 'd', 'u', 'i', 'g', 'l', 'b', 'k', 'r', 'z', 't', 'n', 'w', 'j', 'p', 'f', 'm', 'a', 'q'};
	int ch, i, n;
	FILE *f_in, *f_out;
	if (!(f_in = fopen("A.in", "r")))
	{
		puts("ERROR: no input file.\n");
		return EXIT_FAILURE;
	}
	f_out = fopen("A.out", "w+");
	fscanf(f_in, "%d\n", &n);
	for(i = 0; i < n; i++)
	{
		fprintf(f_out, "Case #%d: ", i+1);
		ch = fgetc(f_in);
		while(ch > 31)
		{
			if (ch == 32)
			{
				fprintf(f_out, " ");
			}
			else
			{
				printf("%d,", ch-97);
				fprintf(f_out, "%c", (char) trad[ch-97]);
			}
			ch = fgetc(f_in);
		}
		fprintf(f_out, "\n");
	}
	fclose(f_in);
	fclose(f_out);
	return EXIT_SUCCESS;
}
