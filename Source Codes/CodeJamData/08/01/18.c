#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct problem_input_record
{
    int engine_no;
    char engines[100][256];
    int query_no;
    char queries[1000][256];
    
    int switch_no;
};


/* lookup the engine which matches the given query */
int
find_engine(struct problem_input_record *record, int query_idx)
{
    int engine_idx;

    for (engine_idx=0; engine_idx < record->engine_no; engine_idx++)
    {
	if (!strcmp(record->engines[engine_idx], record->queries[query_idx]))
	    return engine_idx;
    }

    return -1;
}

int
get_an_answer(struct problem_input_record *record)
{
    int query_idx, engine_idx;
    int engine_seen[100];
    int remain_engines;

    memset(engine_seen, 0, sizeof(engine_seen));
    remain_engines = record->engine_no;

    for (query_idx=0; query_idx < record->query_no; query_idx++)
    {
	engine_idx = find_engine(record, query_idx);

// printf("idx=%d, remains=%d\n", engine_idx, remain_engines);

	/* no such engine. - great. continue */
	if (engine_idx < 0) continue;

	if (engine_seen[engine_idx] == 0) 
	{
	    /* new found */
	    engine_seen[engine_idx] = 1;
	    remain_engines--;
	}

	if (remain_engines == 0)
	{
	    /* no more engine left - we have to switch */
	    record->switch_no++;

	    memset(engine_seen, 0, sizeof(engine_seen));
	    remain_engines = record->engine_no;

	    /* The last one is a new starting position */
	    engine_seen[engine_idx] = 1;
	    remain_engines--;
	}
    }

    return 0;
}

int
read_a_record(FILE *fp, struct problem_input_record *record)
{
    char buf[256];
    int nread;
    int i;
    char *p;

    /* read engines */
    if (fgets(buf, 256, fp) == NULL) return -1;
    nread = sscanf(buf, "%d", &record->engine_no);
    if (nread != 1) return -1;

//    printf("%d: engines\n", record->engine_no);

    for (i=0; i<record->engine_no; i++)
    {
	p = fgets(record->engines[i], 256, fp);
	if (p == NULL) return -1;

	p = strchr(record->engines[i], '\n');
	if (p != NULL) *p = '\0';
//    printf("[%s]\n", record->engines[i]);
    }
    
    /* read queries */
    if (fgets(buf, 256, fp) == NULL) return -1;
    nread = sscanf(buf, "%d", &record->query_no);
    if (nread != 1) return -1;

//    printf("%d: queries\n", record->query_no);

    for (i=0; i<record->query_no; i++)
    {
	p = fgets(record->queries[i], 256, fp);
	if (p == NULL) return -1;

	p = strchr(record->queries[i], '\n');
	if (p != NULL) *p = '\0';
//    printf("[%s]\n", record->queries[i]);
    }
    
    return 0;
}

int
solve_the_problem(char *filename)
{
    FILE *fp;
    int i, n;
    struct problem_input_record *record;

    record = malloc(sizeof(struct problem_input_record));

    fp = fopen(filename, "r");
    if (fp == NULL) return -1;

    fscanf(fp, "%d\n", &n);

    for (i=0; i<n; i++)
    {
	memset(record, 0, sizeof(struct problem_input_record));

	if (read_a_record(fp, record) != 0)
	{
	    printf("failed to parse an input file\n");
	    fclose(fp);
	    return -2;
	}

	get_an_answer(record);

	printf("Case #%d: %d\n", i+1, record->switch_no);
    }

    fclose(fp);

    return 0;
}


int
main(int argc, char *argv[])
{
    int ret;

    /* load an input file */
    ret = solve_the_problem(argv[1]);
    if (ret != 0)
    {
	printf("somthing wrong [%s].\n", argv[1]);
	return -1;
    }

    return 0;
}
