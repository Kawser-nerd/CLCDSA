/*
AtCoder Regular Contest 021 A - DEAD END
??:
*/

//#include<stdio.h>
//#include<string.h>
//#include<math.h>
//#include<stdlib.h>
//
//#define DEBUG1
//#define DEBUG2
//#define DEBUGF
//
//#ifdef DEBUG1
//#ifdef DEBUG2
//#ifdef DEBUGF
//#endif
//#define int long long

#include<stdio.h>

//#define DEBUG1
//#define DEBUG2
//#define DEBUGF

int main(void) {
	int i,a[5][5] = {0};
	for (i = 0; i < 16;i++) { scanf("%d", &a[i / 4][i % 4]); }
	for (i = 0; i < 16; i++) {
		if (a[i / 4][i % 4] == a[i / 4][i % 4 + 1] || a[i / 4][i % 4] == a[i / 4 + 1][i % 4]) {
			break;
		}
	}
	if (i == 16) {
		printf("%s\n", "GAMEOVER");
	}
	else {
		printf("%s\n", "CONTINUE");
	}


#ifdef DEBUGF
	getch();
#endif
	return 0;
}


//a = (int)sqrt((double)n) + 1;
//int ngflg = 0;
//scanf("%d", &n);
//scanf("%lld", &N);
//
//#define int long long
//signed main() {
//int *x = (int *)malloc(sizeof(int) * N);
//int *y = (int *)malloc(sizeof(int) * N);
//int desc(const void *a, const void *b) {return *(int *)b - *(int *)a;}
//qsort(num, 3, sizeof(int), desc);
//int d = pow(2, k);
//
//int a, b, c, d, ngflg = 0;
//int a[100], b[100];
//scanf("%d %d", &t, &n);
//for (int i = 0; i < n; i++) {
//	scanf("%d", &a[i]);
//}
//scanf("%d", &m);
//for (int i = 0; i < m; i++) {
//	scanf("%d", &b[i]);
//}
//#ifdef DEBUG1
//for (int i = 0; i < n; i++) {
//	printf("%d\n", a[i]);
//}
//for (int i = 0; i < m; i++) {
//	printf("%d\n", b[i]);
//}
//#endif
//int i = 0, j = 0;
//scanf("%d %d %d %d", &a, &b, &c, &d);
//
//if ((c - a)*(c - a) <= d*d) { printf("%s\n", "Yes"); }
//else if ((c - b)*(c - b) <= d*d && (a - b)*(a - b) <= d*d) { printf("%s\n", "Yes"); }
//else { printf("%s\n", "No"); }
//
//if (a*a > b*b) { printf("%s\n", "Ant"); }
//if (a*a < b*b) { printf("%s\n", "Bug"); }
//if (a*a == b*b) { printf("%s\n", "Draw"); } ./Main.c: In function ‘main’:
./Main.c:29:28: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  for (i = 0; i < 16;i++) { scanf("%d", &a[i / 4][i % 4]); }
                            ^