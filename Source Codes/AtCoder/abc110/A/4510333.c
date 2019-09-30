/*
 * main.c
 *
 *  Created on: 2019/03/09
 *      Author: family
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int sort_inc(const void *a, const void *b)
{
	return (*(int*)a - *(int*)b);
}
int main()
{
	int a[3] = {0};
	scanf("%d %d %d", &a[0], &a[1], &a[2]);
	qsort(a, 3, sizeof(int), sort_inc);
	printf("%d\n", (a[2]*10) + (a[1]) + a[0]);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:21:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d %d", &a[0], &a[1], &a[2]);
  ^