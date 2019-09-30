#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdint.h>

#define LARGE_BUF	4096

void calculate(char a, char b, int *signedness, char *res)
{
	if (b == '1') {
		*res = a;
	} else if (a == 'i' && b == 'i') {
		*res = '1';
		*signedness *= -1;
	} else if (a == 'i' && b == 'j') {
		*res = 'k';
	} else if (a == 'i' && b == 'k') {
		*res = 'j';
		*signedness *= -1;
	} else if (a == 'j' && b == 'i') {
		*res = 'k';
		*signedness *= -1;
	} else if (a == 'j' && b == 'j') {
		*res = '1';
		*signedness *= -1;
	} else if (a == 'j' && b == 'k') {
		*res = 'i';
	} else if (a == 'k' && b == 'i') {
		*res = 'j';
	} else if (a == 'k' && b == 'j') {
		*res = 'i';
		*signedness *= -1;
	} else if (a == 'k' && b == 'k') {
		*res = '1';
		*signedness *= -1;
	} else {
		printf("*** ERROR: %c %c ***\n", a, b);
		sleep(10);
	}
}

int validate(uint64_t word_cnt, uint64_t multiplier, char *dbuf)
{
	int hasi = 0;
	int hasj = 0;
	int hask = 0;

	int i;

	for (i = 0; i < word_cnt; i++) {
		if (dbuf[i] == 'i')
			hasi = 1;
		else if (dbuf[i] == 'j')
			hasj = 1;
		else if (dbuf[i] == 'k')
			hask = 1;

		if (hasi && hasj && hask)
			break;
	}

	if ((!hasi && !hasj) ||
			(!hasi && !hask) ||
			(!hasj && !hask))
		return 0;

	if (word_cnt * multiplier < 3)
		return 0;

	if (word_cnt * multiplier == 3 && strcmp(dbuf, "ijk"))
		return 0;

	if (word_cnt * multiplier == 4 &&
			strcmp(dbuf, "jkjk") &&
			strcmp(dbuf, "ikik") &&
			strcmp(dbuf, "ijij"))
		return 0;

	return 1;
}

int get_result(uint64_t word_cnt, uint64_t multiplier, char *dbuf)
{
	int signedness = 1;
	uint64_t i;
	char tmp;
	int mod = 1;

	if (!validate(word_cnt, multiplier, dbuf))
		return 0;

	calculate(dbuf[0], dbuf[1], &signedness, &tmp);

	for (i = 2; i < word_cnt; i++) {
		if (tmp == '1') {
			tmp = dbuf[i];
			continue;
		}

		calculate(tmp, dbuf[i], &signedness, &tmp);
	}

	if (tmp != '1') {
		if (multiplier % 2 != 0)
			return 0;

		if ((multiplier / 2) % 2 != 0)
			mod = -1;
	}

	if (multiplier % 2 == 0)
		signedness = 1;

	signedness *= mod;

	if (signedness == -1)
		return 1;


	return 0;
}

int main(int argc, char *argv[])
{
	FILE *fp;
	char buf[4096];
	int cnt;
	int i;

	fp = fopen("test.in", "r");
	if (!fp) {
		printf("Failed to open test.in\n");
		return -1;
	}

	if (!fgets(buf, sizeof(buf), fp)) {
		printf("Failed to fgets: %d\n", __LINE__);
		return -1;
	}

	cnt = atoi(buf);

	for (i = 0; i < cnt; i++) {
		int res;
		uint64_t word_cnt, multiplier;
		char dbuf[100000];
		int len;

		if (!fgets(buf, sizeof(buf), fp)) {
			printf("Failed to fgets #%d\n", i);
			return -1;
		}

		sscanf(buf, "%lu %lu", &word_cnt, &multiplier);

		if (!fgets(dbuf, sizeof(dbuf), fp)) {
			printf("Failed to fgets 2 #%d\n", i);
			return -1;
		}

		len = strlen(dbuf);
		if (dbuf[len - 1] == '\n')
			dbuf[len - 1] = '\0';

		res = get_result(word_cnt, multiplier, dbuf);

		//printf("%s", buf);
		printf("Case #%d: %s\n", i + 1, res ? "YES" : "NO");
		//printf("\n");
	}

	fclose(fp);

	return 0;
}
