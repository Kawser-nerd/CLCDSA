/*
 * b.c
 *
 *  Created on: 22/05/2011
 *      Author: achester
 */

#include <stdio.h>
#include <stdlib.h>


int main(int argc, char **argv) {

	int i, j, n, tn;
	int s1[1000], s2[1000], c[1000];
	int stars;
	int levels;
	int found;
	int starslast;
	int maxstar2;
	int maxnum;

	scanf("%d\n", &tn);
	for (i = 0; i < tn; i++) {

		scanf("%d", &n);
		for (j = 0; j < n; j++) {
			scanf("%d %d\n", &s1[j], &s2[j]);
			c[j] = 0;
		}
		stars = 0;
		levels = 0;
		starslast = 0;
		found = 0;

		while (stars < (2 * n)) {
			starslast=stars;
			for (j = 0; j < n; j++) {
				if (c[j] == 1 && s2[j] <= stars) {
					c[j] = 2;
					stars++;
					levels++;
				}
			}
			//printf("1: %d %d\n", levels, stars);
			for (j = 0; j < n; j++) {
				if (c[j] == 0 && s2[j] <= stars) {
					c[j] = 2;
					stars += 2;
					levels++;
				}
			}
			//printf("2: %d %d\n", levels, stars);
			if (stars == starslast) {
				maxnum=-1;
				maxstar2=-1;
				for (j = 0; j < n; j++) {
					if (c[j] == 0 && s1[j] <= stars) {
						if(maxstar2<s2[j]){
							maxstar2=s2[j];
							maxnum=j;
						}
					}
				}
				if(maxnum>=0){
					c[maxnum]=1;
					stars++;
					levels++;
				}
			//	printf("3: %d %d\n", levels, stars);
			}
			if (stars == starslast) {
				printf("Case #%d: Too Bad\n", i + 1);
				found = 1;
				break;
			}
		}

		if (found == 1) {
			continue;
		}

		printf("Case #%d: %d\n", i + 1, levels);

	}

}
