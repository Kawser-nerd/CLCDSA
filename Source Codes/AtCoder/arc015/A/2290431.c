/*
AtCoder Regular Contest 015 A - Celsius ? Fahrenheit ??:
*/

#include<stdio.h>

//#define DEBUG1
//#define DEBUGF

int max(int a, int b) {return a >= b ? a : b;}

int main() {
	int n;
	float ans;
	scanf("%d", &n);
	ans = ((9.0/5.0)*n+32) ;
	printf("%f\n", ans);
#ifdef DEBUG1
#endif
#ifdef DEBUGF
	getch();
#endif
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:15:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &n);
  ^