/*
B - 2?????????? ( Maximum and Minimum )
Ver1
??:
*/

#include<stdio.h>

//#define DEBUG1
//#define DEBUG2

int main() {
	int n;
	int d[501];
	int sum = 0;
	int max = 0;
	int min = 0;

	/*??
	*/
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &d[i]);
	}

	/*sum???
	  max???
	*/
	for (int i = 0; i < n; i++) {
		sum = sum + d[i];
		if (max < d[i]) { max = d[i]; }
	}

	/*min???
	*/

	if (max > sum - max) {min = max - (sum - max);}
	if (max < sum - max) {min = 0;}
	if (sum == max) { min = max; }

	printf("%d\n", sum);
	printf("%d\n", min);

#ifdef DEBUG2
	getch();
#endif
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:21:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &n);
  ^
./Main.c:23:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &d[i]);
   ^