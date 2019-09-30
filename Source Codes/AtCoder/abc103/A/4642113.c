#include<stdio.h>
#include<stdlib.h>

void swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

int main()
{
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	if(a < b) swap(&a, &b);
	if(a < c) swap(&a, &c);
	if(b < c) swap(&b, &c);
	printf("%d\n", abs(a-b)+abs(b-c));
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:14:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d %d", &a, &b, &c);
  ^