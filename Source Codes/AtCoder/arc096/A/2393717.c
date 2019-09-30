#include <stdio.h>

void Sub(int total, int total2, int total3);
int main(void) {
	int a, b, c, x, y, total = 0, total2 = 0, total3 = 0;
	scanf("%d %d %d %d %d", &a, &b, &c, &x, &y);
	total = a * x + b * y;
	total2 = c * 2 * (x > y ? x : y);
	total3 = c * 2 * (x < y ? x : y) + a * (x - (x < y ? x : y)) + b * (y - (x < y ? x : y));
	//printf("%d %d %d\n", total, total2, total3);
	Sub(total, total2, total3);
	return 0;
}

void Sub(int total, int total2, int total3)
{
	int min = total;
	
	if(min>total2) min = total2;
	if(min>total3) min = total3;
	printf("%d\n", min);
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d %d %d %d", &a, &b, &c, &x, &y);
  ^