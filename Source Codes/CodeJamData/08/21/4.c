#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX 100000

typedef struct {
	long long x, y;
} Point;

Point points[MAX];

long long calculate(int npoints) {
	int i, j, k;
	long long total = 0;
	for (i = 0; i < npoints; i++) {
		for (j = i+1; j < npoints; j++) {
			for (k = j+1; k < npoints; k++) {
				long long sumx = points[i].x + points[j].x + points[k].x;
				long long sumy = points[i].y + points[j].y + points[k].y;
				//printf("sumx = %lld, sumy = %lld\n", sumx, sumy);
				if (sumx % 3 == 0 && sumy % 3 == 0) {
					total++;
				}
			}
		}
	}
	return total;
}

int main(int argc, char **argv) {
	int cases;
	int i, j;
	int n;
	long long A, B, C, D, x0, y0, M;
	long long x, y;
	
	scanf("%d", &cases);
	for (i = 0; i < cases; i++) {
		scanf("%d %lld %lld %lld %lld %lld %lld %lld",
			   &n, &A, &B, &C, &D, &x0, &y0, &M);
		
		x = x0;
		y = y0;
		points[0].x = x;
		points[0].y = y;
		//printf("Point: (%lld, %lld)\n", x, y);
		for (j = 1; j < n; j++) {
			x = (A * x + B) % M;
			y = (C * y + D) % M;
			points[j].x = x;
			points[j].y = y;
			//printf("Point: (%lld, %lld)\n", points[j].x, points[j].y);
		}
		
		long long total = calculate(n);
		
		printf("Case #%d: %lld\n", i+1, total);
	}
	
	return 0;
}
