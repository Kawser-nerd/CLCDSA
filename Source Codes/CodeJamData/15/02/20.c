#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int get_max(int cnt, int *plates, int *max, int *second_max)
{
	int i;
	int num_max = 0;

	*max = 0;

	for (i = 0; i < cnt; i++) {
		if (plates[i] > *max) {
			*second_max = *max;
			*max = plates[i];
			num_max = 1;
		} else if (plates[i] == *max) {
			num_max++;
		}
	}

	return num_max;
}

int get_large_enough(int threshold, int cnt, int *plates)
{
	int i;
	int num = 0;

	for (i = 0; i < cnt; i++) {
		if (plates[i] > threshold)
			num++;
	}

	return num;
}

int valid_for_nine(int cnt, int *plates)
{
	int i;
	int num_nine = 0;

	if (cnt == 1)
		return 1;

	for (i = 0; i < cnt; i++) {
		if (plates[i] == 9) {
			num_nine++;
			if (num_nine > 1)
				return 0;

			continue;
		}
		if (plates[i] > 3 && plates[i] != 6)
			return 0;
	}

	return 1;
}

int share_plates(int threshold, int *num_plates, int *plates, int special)
{
	int i;
	int cnt = *num_plates;
	int minutes = 0;

	for (i = 0; i < cnt; i++) {
		if (plates[i] > threshold) {
			int tmp = plates[i];

			if (plates[i] == 9 && special) {
				plates[i] = tmp / 3;
				plates[*num_plates] = (tmp / 3) * 2;
			} else {
				plates[i] = (tmp / 2) + (tmp % 2);
				plates[*num_plates] = tmp / 2;
			}

			(*num_plates)++;
			minutes++;
		}
	}

	return minutes;
}

int get_minutes(int num_plates, char *buf)
{
	int minutes = 0;
	int i;
	int plates[1000000] = {0};
	char *tmp = buf;
	int max;
	int second_max;
	int num_large_enough;
	int threshold;

	for (i = 0; i < num_plates; i++) {
		int num_pancakes;
		sscanf(tmp, "%d ", &num_pancakes);

		plates[i] = num_pancakes;

		tmp = strchr(tmp, ' ') + 1;
	}

	while (1) {
		get_max(num_plates, plates, &max, &second_max);

		if (max <= 2)
			break;

		threshold = (max / 2) + (max % 2);
		num_large_enough = get_large_enough(threshold, num_plates, plates);

		while (num_large_enough >= threshold) {
			threshold++;

			if (threshold == max) {
				goto finish;
			}

			num_large_enough = get_large_enough(threshold, num_plates, plates);
		}

		if (num_large_enough + threshold > max) {
			goto finish;
		}

		minutes += share_plates(threshold, &num_plates, plates, valid_for_nine(num_plates, plates));
	}

finish:
	minutes += max;

	return minutes;
}

#define LARGE_BUF	2000000
int main(int argc, char *argv[])
{
	FILE *fp;
	char buf[4096];
	char *dbuf;
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

	dbuf = calloc(LARGE_BUF, 1);

	for (i = 0; i < cnt; i++) {
		int num_plates;
		int res;

		if (!fgets(buf, sizeof(buf), fp)) {
			printf("Failed to fgets #%d\n", i);
			return -1;
		}

		num_plates = atoi(buf);

		if (!fgets(dbuf, LARGE_BUF, fp)) {
			printf("Failed to fgets dbuf #%d\n", i);
			return -1;
		}

		res = get_minutes(num_plates, dbuf);

		printf("%s", dbuf);
		printf("Case #%d: %d\n", i + 1, res);
		printf("\n");
	}

	free(dbuf);

	fclose(fp);

	return 0;
}
