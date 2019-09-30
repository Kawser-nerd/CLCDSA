#include<stdio.h>

int main()
{
	int x[4], y[4], x_diff, y_diff; 
	
	scanf("%d %d %d %d", &x[0], &y[0], &x[1], &y[1]);
	
	x_diff = x[1] - x[0];
	y_diff = y[1] - y[0];
	
	x[2] = x[1] - y_diff;
	y[2] = y[1] + x_diff;
	
	x[3] = x[2] - x_diff;
	y[3] = y[2] - y_diff;
	
	printf("%d %d %d %d", x[2], y[2], x[3], y[3]);

	return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d %d %d", &x[0], &y[0], &x[1], &y[1]);
  ^