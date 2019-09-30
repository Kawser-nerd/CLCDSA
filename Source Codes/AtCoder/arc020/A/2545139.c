/*
AtCoder Regular Contest 020 A – ?????????
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
#include<math.h>

//#define DEBUG1
//#define DEBUG2
//#define DEBUGF

int a, b;

int main(void) {
	scanf("%d %d", &a, &b);
	if (a*a == b*b) { printf("%s\n", "Draw"); }
	if (a*a < b*b) { printf("%s\n", "Ant"); }
	if (a*a > b*b) { printf("%s\n", "Bug"); }

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
./Main.c:31:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d", &a, &b);
  ^