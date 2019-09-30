#include <stdio.h>
#include <stdlib.h>


int main(int argc, char **argv)
{
	FILE			*in;
	FILE			*out;
	unsigned long	num_cases;
	unsigned long	cur_case;
	unsigned long	i, j;
	unsigned long	Min;
	unsigned long	Max;
	char			str[100];
	unsigned long	queries[1000];
	unsigned long	n;
	long			v1[800];
	long			v2[800];
	long			temp;
	long long		sc;

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
		for(i = 0; i < n; i++)
		{
			fscanf(in, "%ld", &v1[i]);
		}
		fscanf(in, "\n");
		for(i = 0; i < n; i++)
		{
			fscanf(in, "%ld", &v2[i]);
		}
		fscanf(in, "\n");

		sc = 0;
		for(i = 0; i < (n - 1); i++)
		{
			Min = i;
			Max = i;
			for(j = i + 1; j < n; j++)
			{
				if(v1[Min] > v1[j])
					Min = j;
				if(v2[Max] < v2[j])
					Max = j;
			}
			temp = v1[i];
			v1[i] = v1[Min];
			v1[Min] = temp;
			temp = v2[i];
			v2[i] = v2[Max];
			v2[Max] = temp;
			sc += v1[i] * v2[i];
		}
		sc += v1[i] * v2[i];

		fprintf(out, "Case #%lu: %lld\n", cur_case + 1, sc);
	}

	fclose(in);
	fclose(out);
	return 1;
}
