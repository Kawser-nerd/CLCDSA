/*
 * main.c
 *
 *  Created on: 2019/02/24
 *      Author: family
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int a[9] = {111, 222, 333, 444, 555, 666, 777, 888, 999};

int main()
{
	int n = 0;
	int i = 0;
	scanf("%d",&n);

	for(i = 0; i < 9; i++) {
		if (n <= a[i]) {
			break;
		}
	}
	printf("%d\n", a[i]);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:20:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^