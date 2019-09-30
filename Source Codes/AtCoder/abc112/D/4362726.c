/*
 * main.c
 *
 *  Created on: 2019/02/21
 *      Author: family
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int data[100] = {0};

int main()
{
	int n, m;
	int val, val2, ans;
	int temp;
	scanf("%d %d", &n, &m);
	val = m/n;
	val2 = val + (m%n);

	if (val == val2) {
		ans = val;
	} else {
		temp = val;
		while(temp > 0) {
			if (m%temp == 0) {
				ans = temp;
				break;
			} else {
				temp--;
			}
		}
	}

	printf("%d\n",ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:21:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d", &n, &m);
  ^