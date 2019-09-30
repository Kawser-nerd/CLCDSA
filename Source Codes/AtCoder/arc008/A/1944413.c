/*
AtCoder Regular Contest 008 A - ??????????
Ver1
??:
*/

#include<stdio.h>

//#define DEBUG1

int main() {
	int n, t, i, ans;

	scanf("%d", &n);

	t = n / 10;
	i = n % 10;
	if (i >= 7) {
		t++; 
		i = 0;
	}
	else
	{
		i = i * 15;
	}
	ans = t * 100 + i;
#ifdef DEBUG1
	printf("%d\n", ans);
	getch();
#endif
	printf("%d\n", ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:14:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &n);
  ^