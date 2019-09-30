#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

FILE* fin;
FILE* fout;
	
double distant(int x1, int y1, int x2, int y2) {
	return (double) sqrt((x1-x2) * (x1-x2) + (y1-y2)*(y1-y2));
}
	
double min(double a, double b) {
	return a > b ? b : a;
}	
double max(double a, double b) {
	return a < b ? b : a;
}	

	
int main() {
	fin = fopen("c.in", "r");
	fout = fopen("c.out", "w");
	
	int num_test, t;
	fscanf(fin, "%d\n", &num_test);
	
	int i;
	for (t = 1; t <= num_test; t++) {
		int n;
		int x1, y1, r1, x2, y2, r2, x3, y3, r3;
		
		
		fscanf(fin, "%d\n", &n);
		if (n == 1) {
			fscanf(fin, "%d %d %d\n", &x1, &y1, &r1);
			fprintf(fout, "Case #%d: %.6f\n", t, (double)r1);
		}
		else if (n == 2) {
			fscanf(fin, "%d %d %d\n", &x1, &y1, &r1);
			fscanf(fin, "%d %d %d\n", &x2, &y2, &r2);
			fprintf(fout, "Case #%d: %.6f\n", t, (double)(r1 > r2 ? r1 : r2));
		} else {
			fscanf(fin, "%d %d %d\n", &x1, &y1, &r1);
			fscanf(fin, "%d %d %d\n", &x2, &y2, &r2);
			fscanf(fin, "%d %d %d\n", &x3, &y3, &r3);
			
			// x1 x2 - x3
			double mr, minn = 999999;
			double min1 = 99999, min2 = 99999, min3 = 99999;
			
			mr = distant(x1, y1, x2, y2) + r1 + r2;
			mr = mr/2;
			mr = max(mr, r3);
			min1 = mr;
			
			mr = distant(x2, y2, x3, y3) + r2 + r3;
			mr = mr/2;
			mr = max(mr, r1);
			min2 = mr;
			
			mr = distant(x3, y3, x1, y1) + r3 + r1;
			mr = mr/2;
			mr = max(mr, r2);
			min3 = mr;
			
			minn = min(min(min1, min2), min3);
			
			fprintf(fout, "Case #%d: %.6f\n", t, minn);
		}
	}
	
	printf("%d", t);
	
	return 0;	
}

