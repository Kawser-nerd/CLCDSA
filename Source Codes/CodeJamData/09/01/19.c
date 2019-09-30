#include <stdio.h>

#define FILE_NAME	"test.in"

int match_pattern(char *pattern, char *word)
{
	int i = 0;
	char *pattern_data = NULL;
	char *word_data = NULL;
	int in_group = 0;
	int match_group = 0;

	for (pattern_data = pattern, word_data = word; 
		'\0' != *pattern_data && '\0' != *word_data; 
		pattern_data++) {
		if ('(' == *pattern_data) {
			if (0 == in_group) {
				in_group = 1;
			} else {
				goto err;
			}
		} else if (')' == *pattern_data) {
			if (1 == in_group && 1 == match_group) {
				in_group = 0;
				match_group = 0;
				word_data++;
			} else {
				goto err;
			}
		} else if (*pattern_data >= 'a' && *pattern_data <= 'z') {
			if (1 == in_group) {
				if (0 == match_group) {
					if (*word_data == *pattern_data) {
						match_group = 1;
					} 
				}
			} else {
				if (*word_data == *pattern_data) {
					word_data++;
				} else {
					goto err;
				}
			}
		} else {
			goto err;
		}
	}	

	if ('\0' == *pattern_data && '\0' == *word_data) {
		return 0;
	}

err:
	return -1;
}


main()
{
	FILE *fp = NULL;
	char line[1000000];
	char words[5000][16] = {0};
	int l = 0, d = 0, n = 0;
	int i = 0, j = 0;
	int count = 0;

	fp = fopen(FILE_NAME, "r");

	if (!fp) {
		goto err;
	}

	if (fgets(line, sizeof(line), fp)) {
		sscanf(line, "%d %d %d", &l, &d, &n);
	} else {
		goto err;
	}

	if (l < 1 || d < 1 || n < 1 || l > 15 || d > 5000 || n > 500) {
		goto err;
	}

	for (i = 0; i < d; i++) {
		if (fgets(line, sizeof(line), fp)) {
			line[strlen(line) - 1] = '\0';
			strncpy(words[i], line, sizeof(words) - 1);
		} else {
			goto err;
		}
	}

	for (i = 0; i < n; i++) {
		if (fgets(line, sizeof(line), fp)) {
			line[strlen(line) - 1] = '\0';
			for (count = 0, j = 0; j < d; j++) {
				if (0 == match_pattern(line, words[j])) {
					count++;
				}
			}
			printf("Case #%d: %d\n", i + 1, count);
		} else {
			goto err;
		}
	}

err:
	if (fp) {
		fclose(fp);
		fp = NULL;
	}
	return 0;
}
