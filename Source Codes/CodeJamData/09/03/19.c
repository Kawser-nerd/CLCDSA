#include <stdio.h>

#define FILE_NAME	"test.in"
#define KEYWORD		"welcome to code jam"
#define KEYWORD_LEN	19

int match_keyword(char *text)
{
	int part_match[KEYWORD_LEN][512];
	int i = 0, j = 0;
	int text_length = strlen(text);
	char key[KEYWORD_LEN + 1] = KEYWORD;
	int times = 0;

	for (times = 0, j = 0; j < text_length; j++) {
		if (text[j] == key[i]) {
			times++;
		}
		part_match[i][j] = times;
	}
	
	for (i = 1; i < KEYWORD_LEN; i++) {
		for (j = 0; j < i; j++) {
			part_match[i][j] = 0;
		}

		for (j = i; j < text_length; j++) {
			if (text[j] == key[i]) {
				part_match[i][j] = 
					(part_match[i][j - 1] + part_match[i - 1][j - 1]) % 10000;
			} else {
				part_match[i][j] = part_match[i][j - 1];
			}
		}

	}

	return part_match[KEYWORD_LEN - 1][text_length - 1];
}

main()
{
	FILE *fp = NULL;
	char line[1000000];
	int n = 0;
	int i = 0, j = 0;
	int count = 0;

	fp = fopen(FILE_NAME, "r");

	if (!fp) {
		goto err;
	}

	if (fgets(line, sizeof(line), fp)) {
		sscanf(line, "%d", &n);
	} else {
		goto err;
	}

	if (n < 1 || n > 100) {
		goto err;
	}

	for (i = 0; i < n; i++) {
		if (fgets(line, sizeof(line), fp)) {
			line[strlen(line) - 1] = '\0';
			if (strlen(line) > 500) {
				goto err;
			}
			count = match_keyword(line);
			printf("Case #%d: %04d\n", i + 1, count);
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
