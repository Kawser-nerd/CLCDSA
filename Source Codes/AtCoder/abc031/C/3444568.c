/*

??:
*/
#define _USE_MATH_DEFINES
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>  
#include <stdbool.h>   
#define inf (INT_MAX-1)
#define INF 9223372036854775807
#define PI 3.14159265358979323846;
#define EPS 1e-10
#define sq(n) ((n)*(n))
#define rep(i,n) for(i=0;i<n;i++)
#define rev(i,n) for(i=n-1;i>=0;i--)
/*
#define sort(a,n) qsort(a,n,sizeof(TYPE),cmp)
#define sort_r(a,n) qsort(a,n,sizeof(TYPE),cmp_r)
*/
#define chsort(s,n) qsort(s,n,sizeof(char),cmp)
#define chsort_r(s,n) qsort(s,n,sizeof(char),char_cmp_r)
#define TYPE long long
#define ll long long
#define MEMSET(a) memset(a,0,sizeof(a))
#define MEMSET_U(a) memset(a,-1,sizeof(a))
const int mod = (int)1e09 + 7;

//#define DEBUG1
//#define DEBUG2
//#define DEBUGF
#define DUMMY

int in(void) { int i; scanf("%d", &i); return i; }
long long llin(void) { long long i; scanf("%lld", &i); return i; }
double din(void) { double i; scanf("%lf", &i); return i; }
void chin(char s[]) { scanf("%s", s); }

void print(int a) { printf("%d\n", a); }
void llprint(long long a) { printf("%lld\n", a); }
void dprint(double a) { printf("%.10f\n", a); }
void print2(int a, int b) { printf("%d %d\n", a, b); }
int Max(int a, int b) { if (a > b) { return a; }return b; }
int Min(int a, int b) { if (a < b) { return a; }return b; }
long long llmax(long long a, long long b) { return a > b ? a : b; }
long long llmin(long long a, long long b) { return a < b ? a : b; }
double dmax(double a, double b) { return a > b ? a : b; }
double dmin(double a, double b) { return a < b ? a : b; }
//long long llmax(long long a, long long b) { return a > b ? a : b; }
//long long llmin(long long a, long long b) { return a < b ? a : b; }
//double dmax(double a, double b) { return a > b ? a : b; }
int cmp(const void *a, const void *b) { return *(TYPE *)a - *(TYPE *)b; }
int cmp_r(const void *a, const void *b) { return *(TYPE *)b - *(TYPE *)a; }
int char_cmp(const void *a, const void *b) { return strcmp((char *)a, (char *)b); }
int char_cmp_r(const void *a, const void *b) { return strcmp((char *)b, (char *)a); }
void swap(int *a, int *b) { int t = *a; *a = *b; *b = t; }

//A
//int main() {
//	int A, D,ans;
//	scanf("%d%d", &A, &D);
//	if (A == D) { A++; }
//	else if (A < D) { A++; }
//	else { D++; }
//	ans = A*D;
//	printf("%d\n", ans);
//
//#ifdef DEBUGF
//	getch();
//#endif
//	return 0;
//}

//B
//int main() {
//	int L, H, N;
//	int n;
//	int ans;
//	scanf("%d%d%d", &L, &H, &N);
//	int *A = (int *)malloc(sizeof(int) * N);
//	for (n = 0; n < N; n++) {
//		scanf("%d", &A[n]);
//	}
//	for (n = 0; n < N; n++) {
//		ans = -1;
//		if (A[n] <= H && A[n] >= L) { ans = 0; }
//		else if (A[n] < L) { ans = L - A[n]; }
//		printf("%d\n", ans);
//	}
//#ifdef DEBUGF
//	getch();
//#endif
//	return 0;
//	}

////C
//int main() {
//
//	int N, a[50] = { 0 };
//	int aoki = 0, takahasi = 0;
//	int takahasimax = -1000000, aokimax = -10000000, mmax = 0;
//
//	scanf("%d", &N);
//	for (int i = 0; i < N; i++) {
//		scanf("%d", &a[i]);
//	}
//	for (int k = 0; k < N; k++) {//????k?????
//		for (int m = 0; m < k; m++) {//???m?????(m<k)
//			for (int o = m + 1; o <= k; o += 2) {//???m???(m<k)
//				aoki = aoki + a[o];
//			}
//			if (aokimax < aoki) {
//				aokimax = aoki;
//				mmax = m;
//			}
//			aoki = 0;
//		}
//		for (int m = k + 1; m < N; m++) {//???m?????(k<m)
//			for (int n = k + 1; n <= m; n += 2) {//?????m???
//				aoki = aoki + a[n];
//			}
//			if (aokimax < aoki) {
//				aokimax = aoki;
//				mmax = m;
//			}
//			aoki = 0;
//		}
//		//???????
//
//		if (k < mmax) {
//			for (int p = k; p <= mmax; p += 2) {
//				takahasi = takahasi + a[p];
//				//printf("+%d\n",a[p]);
//			}
//			if (takahasimax < takahasi) {
//				takahasimax = takahasi;
//			}
//			//               printf("%d %d %d\n",mmax,k,takahasi);
//			takahasi = 0;
//		}
//		else {
//			for (int q = mmax; q <= k; q += 2) {
//				takahasi = takahasi + a[q];
//			}
//			if (takahasimax < takahasi) {
//				takahasimax = takahasi;
//			}
//			//   printf("%d %d %d\n",mmax,k,takahasi);
//			takahasi = 0;
//		}
//		aokimax = -1000000;
//	}
//	printf("%d\n", takahasimax);
//
//#ifdef DEBUGF
//	getch();
//#endif
//	return 0;
//}

//C
//??
//????ta???????
//????ao(ao<ta)???????
//???????aomax???
//??????aoki_max???
//????ao(ao>ta)???????
//???????aomax???
//??????aoki_max???
//????????
//ta<aomax???
//aomax<ta???
//??????????takahasi_max???

int main() {

	int N, a[50] = { 0 };
	int aoki = 0, takahasi = 0;
	int takahasimax = -1000000, aokimax = -10000000, mmax = 0;

	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &a[i]);
	}
	//????ta???????
	for (int k = 0; k < N; k++) {
		//????ao(ao<ta)???????
		for (int m = 0; m < k; m++) {
			for (int o = m + 1; o <= k; o += 2) {
				aoki = aoki + a[o];
			}
			if (aokimax < aoki) {
				//??????aoki_max???
				aokimax = aoki;
				//???????aomax???
				mmax = m;
			}
			aoki = 0;
		}
		//????ao(ao>ta)???????
		for (int m = k + 1; m < N; m++) {
			for (int n = k + 1; n <= m; n += 2) {
				aoki = aoki + a[n];
			}
			if (aokimax < aoki) {
				//??????aoki_max???
				aokimax = aoki;
				//???????aomax???
				mmax = m;
			}
			aoki = 0;
		}
		//????????	
		//ta<aomax???
		if (k < mmax) {
			for (int p = k; p <= mmax; p += 2) {
				takahasi = takahasi + a[p];
			}
			//??????????takahasi_max???
			if (takahasimax < takahasi) {
				takahasimax = takahasi;
			}
			takahasi = 0;
		}
		else {
			//aomax<ta???
			for (int q = mmax; q <= k; q += 2) {
				takahasi = takahasi + a[q];
			}
			//??????????takahasi_max???
			if (takahasimax < takahasi) {
				takahasimax = takahasi;
			}
			takahasi = 0;
		}
	aokimax = -1000000;
}
printf("%d\n", takahasimax);

#ifdef DEBUGF
getch();
#endif
return 0;
} ./Main.c: In function ‘in’:
./Main.c:36:23: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
 int in(void) { int i; scanf("%d", &i); return i; }
                       ^
./Main.c: In function ‘llin’:
./Main.c:37:37: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
 long long llin(void) { long long i; scanf("%lld", &i); return i; }
                                     ^
./Main.c: In function ‘din’:
./Main.c:38:30: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
 double din(void) { double i; scanf("%lf", &i); return i; }
                              ^
./Main.c: In function ‘chin’:
./Main.c:39:23: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
 void chin(char s[]) { scanf("%s", s); }
                       ^
./Main.c: In function ‘main’:
./Main.c:183:2: warning: ignoring return value of ‘...