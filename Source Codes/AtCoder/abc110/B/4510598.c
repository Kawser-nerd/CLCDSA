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

int xn[100] = {0};
int ym[100] = {0};


int main()
{
	int n, m, x, y;
	int i = 0;
	int maxx, miny;
	scanf("%d %d %d %d", &n, &m, &x, &y);
	maxx = x;
	miny = y;
	for(i = 0; i < n; i++) {
		scanf("%d", &xn[i]);
		if(maxx < xn[i]) {
			maxx = xn[i];
		}
	}
	for(i = 0; i < m; i++) {
		scanf("%d", &ym[i]);
		if(miny > ym[i]) {
			miny = ym[i];
		}
	}
	if (maxx > x) {

	}
	if (maxx < miny)  {
		printf("No War\n");
	} else {
		printf("War\n");
	}

	return 0;
} ./Main.c: In function ‘main’:
./Main.c:23:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d %d %d", &n, &m, &x, &y);
  ^
./Main.c:27:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &xn[i]);
   ^
./Main.c:33:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &ym[i]);
   ^