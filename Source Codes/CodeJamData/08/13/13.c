#include <stdio.h>
#include <stdlib.h>


int main(int argc, char **argv)
{
	FILE			*in;
	FILE			*out;
	unsigned long	num_cases;
	unsigned long	cur_case;
	unsigned long	i;
	unsigned long	n;
	unsigned int	x1;
	unsigned int	x2;
	unsigned int	x3;

	if(argc < 3)
		return 0;
	
	in = fopen(argv[1], "r");
	out = fopen(argv[2], "w");

	if(!in || !out)
	{
		if(in)
			fclose(in);
		if(out)
			fclose(out);
		return 0;
	}

	fscanf(in, "%lu\n", &num_cases);

	for(cur_case = 0; cur_case < num_cases; cur_case++)
	{
		fscanf(in, "%lu\n", &n);

		x1 = 6;
		x2 = 28;
		for(i = 2; i < n; i++)
		{
			x3 = 6 * x2 - 4 * x1 + 4000;
			x3 %= 1000;
			x1 = x2;
			x2 = x3;
		}
		x2 += 999;	
		x2 %= 1000;

		fprintf(out, "Case #%lu: %03lu\n", cur_case + 1, x2);
	}

	fclose(in);
	fclose(out);
	return 1;
}
