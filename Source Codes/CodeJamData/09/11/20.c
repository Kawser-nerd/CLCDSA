#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAXTRY 128
int
is_happy(i, base)
{
	int newres,j;
	int res = i;
	for (j = 0; j < MAXTRY; ++j) {
		newres = 0;
		while (res != 0) {
			int mod = res % base;
			newres += (mod * mod);
			res /= base;
		}
		if (newres == 1)
			return 1;
		res = newres;
	}
	//fprintf(stderr, "WARN: MAXTRY\n");
	return 0;
}

int
find_min_happy(int n, int bases[])
{
	int i, j, allhappy;

	for (i = 2; ; ++i) {
		allhappy = 1;
		for (j = 0; j < n; ++j) {
			if (!is_happy(i, bases[j])) {
				//printf("not h: %d, %d\n", i, bases[j]);
				allhappy = 0;
				break;
			}
		}
		if (allhappy) {
			return i;
		}
	}
	return 1;
}

int
main(int argc, char *argv[])
{
	FILE *f = fopen(argv[1], "r");
	char buf[BUFSIZ];
	int n, i, ary[9];

	fgets(buf, sizeof(buf), f);
	sscanf(buf, "%d", &n);
	for (i = 0; i < n; ++i) {
		int nbase, res;
		fgets(buf, sizeof(buf), f);
		nbase = sscanf(buf, "%d %d %d %d %d %d %d %d %d",
		ary, ary+1, ary+2,ary+3,ary+4,ary+5,ary+6,ary+7,ary+8);
		res = find_min_happy(nbase, ary);
		printf("Case #%d: %d\n", i+1, res);
	}
	return 0;
}
