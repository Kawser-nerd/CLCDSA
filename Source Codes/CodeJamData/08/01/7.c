#include <stdio.h>
#include <stdlib.h>


int main(int argc, char **argv)
{
	FILE			*in;
	FILE			*out;
	unsigned long	num_cases;
	unsigned long	num_engines;
	unsigned long	num_queries;
	unsigned long	num_switches;
	unsigned long	cur_case;
	unsigned long	i;
	unsigned long	q;
	char			str[1001];
	char			*engines[100];
	unsigned long	queries[1000];
	char			engines_cflag[100];
	unsigned long	count_engines;

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
		fscanf(in, "%lu\n", &num_engines);
		for(i = 0; i < num_engines; i++)
		{
			fgets(str, 1001, in);
			engines[i] = (char*)malloc(strlen(str) + 1);
			strcpy(engines[i], str);
		}

		fscanf(in, "%lu\n", &num_queries);
		for(i = 0; i < num_queries; i++)
		{
			fgets(str, 1001, in);
			for(q = 0; q < num_engines && strcmp(str, engines[q]); q++);
			queries[i] = q;
		}
	
		memset(engines_cflag, 0, num_engines);
		count_engines = 0;
		num_switches = 0;

		for(i = 0; i < num_queries; i++)
		{
			if(queries[i] == num_engines || engines_cflag[queries[i]])
				continue;
			count_engines++;
			if(count_engines == num_engines)
			{
				count_engines = 1;
				num_switches++;
				memset(engines_cflag, 0, num_engines);
			}
			engines_cflag[queries[i]] = 1;
		}

		fprintf(out, "Case #%lu: %lu\n", cur_case + 1, num_switches);

		for(i = 0; i < num_engines; i++)
			free(engines[i]);
	}

	fclose(in);
	fclose(out);
	return 1;
}
