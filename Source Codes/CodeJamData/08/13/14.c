#include <stdio.h>

int table[31] = {0, 0, 27, 143, 751, 935, 607, 903, 991, 335, 47, 943, 471, 55, 447, 463, 991, 95, 607, 263, 151, 855, 527, 743, 351, 135, 407, 903, 791, 135, 647};

int main(int argc, char **argv)
{
	int t, n, ret;
	int i;
	scanf("%d", &t);
	for (i = 0; i < t; i++) {
		scanf("%d", &n);
		ret = table[n];
		printf("Case #%d: %03d\n", i + 1, ret);
	}
	return 0;
}
