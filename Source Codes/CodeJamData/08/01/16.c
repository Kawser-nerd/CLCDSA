/*
 * Input
 * Yeehaw
 * NSM
 * Dont Ask
 * B9
 * Googol
 * 10
 * Yeehaw
 * Yeehaw
 * Googol
 * B9
 * Googol
 * NSM
 * B9
 * NSM
 * Dont Ask
 * Googol
 * 5
 * Yeehaw
 * NSM
 * Dont Ask
 * B9
 * Googol
 * 7
 * Googol
 * Dont Ask
 * NSM
 * NSM
 * Yeehaw
 * Yeehaw
 * Googol
 *
 * Output
 * Case #1: 1
 * Case #2: 0
 *
 * Limits
 *
 * 0 < N ≤ 20
 *
 * Small dataset
 *
 * 2 ≤ S ≤ 10
 *
 * 0 ≤ Q ≤ 100
 *
 * Large dataset
 *
 * 2 ≤ S ≤ 100
 *
 * 0 ≤ Q ≤ 1000 
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


static int
is_implode(char** search_engines, int search_engine_index, char* query)
{
	if(strcmp(search_engines[search_engine_index], query) == 0)
		return 1;
	return 0;
}

static int
do_calc(char** search_engines, int num_of_search_engine,
			char** queries,  int num_of_queries)
{
	int i, j, k, max_index;
	int changes;

	changes = 0;
	/* search the longest route */
	for(i = 0; i < num_of_queries; ) {
		max_index = 0;
		/* try all search engines and find the longest one then continue */
		for(j = 0; j < num_of_search_engine; j++) {
			k = i;
			do {
				if(is_implode(search_engines, j, queries[k]))
					break;
				k++;
			} while(k<num_of_queries);
			if(max_index < k) {
				max_index = k;
			}
		}
		i = max_index;
		if(i < num_of_queries)
			changes++;
	}
	return changes;
}

int
main(void)
{
	int test_cases;
	int num_of_search_engine;
	char **search_engines;
	int num_of_queries;
	char **queries;
	int changes;
	int i,j,len;

	if(fscanf(stdin, "%d", &test_cases) != 1) {
		fprintf(stderr, "Cannot read number of test cases\n");
		return 1;
	}

	for(i = 0; i < test_cases; i++) {
		if(fscanf(stdin, "%d\n", &num_of_search_engine) != 1) {
			fprintf(stderr, "Unexpected EOF\n");
			return 1;
		}
		search_engines = (char**)malloc(sizeof(char*)* num_of_search_engine);
		memset(search_engines, 0 , sizeof(char*)*num_of_search_engine);
		for(j = 0; j < num_of_search_engine; j++) {
			len = 0;
			if(getline(&search_engines[j], &len,stdin) == -1) {
				fprintf(stderr, "Unexpected EOF\n");
				return 1;
			}
		}
		if(fscanf(stdin, "%d\n", &num_of_queries) != 1) {
			fprintf(stderr, "Unexpected EOF\n");
			return 1;
		}
		queries = (char**)malloc(sizeof(char*)* num_of_queries);
		memset(queries, 0 , sizeof(char*)*num_of_queries);
		for(j = 0; j < num_of_queries; j++) {
			len = 0;
			if(getline(&queries[j], &len, stdin) == -1) {
				fprintf(stderr, "Unexpected EOF\n");
				return 1;
			}
		}

		changes = do_calc(search_engines, num_of_search_engine,
			queries,  num_of_queries);
		fprintf(stdout, "Case #%d: %d\n", i+1, changes);

		for(j = 0; j < num_of_search_engine; j++) {
			free(search_engines[j]);
		}
		free(search_engines);
		for(j = 0; j < num_of_queries; j++) {
			free(queries[j]);
		}
		free(queries);
	}
}

