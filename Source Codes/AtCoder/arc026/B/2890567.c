/*
AtCoder Regular Contest 026 B - ???
??:
*/

#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>

#define max(x,y)(x<y?y:x)
#define int long long

int compare(const void *a, const void *b) {
	return *(int*)b - *(int*)a;
}

//???
//scanf("%d", &N);
//for (i; i < N; ++i) {
//	scanf("%d", &A[i]);
//	if (b[A[i]] == 1) {
//		ans = max(ans, i - j);
//		while (b[A[i]] == 1) {
//			b[A[j++]] = 0;
//		}
//	}
//	b[A[i]] = 1;
//}
//ans = max(ans, i - j);
//printf("%d\n", ans);

//????????
//static int N, i, j, ans;
//static int A, B;
//static char A[50][51];
//static int cnt, max;
//char *max_name;
//
//scanf("%d", &N);
//for (i = 0; i < N; i++) {
//	scanf("%s", A[i]);
//}
//max_name = A[0];
//for (i = 0; i < N; i++) {
//	cnt = 0;
//	for (j = 0; j < N; j++) {
//		if (strcmp(A[i], A[j]) == 0) {
//			cnt++;
//		}
//		if (cnt > max) {
//			max = cnt;
//			max_name = A[i];
//		}
//	}
//}
//printf("%s\n", max_name);

//#define DEBUG1
//#define DEBUG2
//#define DEBUGF

int main() {
	////static int N, i, j, ans;
	//static int AN, BN, A[100] = {}, B[100] = {}, i, j, ans;
	////static int A, B;
	////static int A, B, C;
	//static int a[31] = {}, b[31] = {}, cnt = 0;
	////static char A[50][51];
	////static int cnt, max;
	////char *max_name;
	////static int ans;

	//scanf("%d %d", &AN, &BN);
	//for (i = 0; i < AN; i++) {
	//	scanf("%d", &A[i]);
	//	a[A[i]]++;
	//}
	//for (i = 0; i < BN; i++) {
	//	scanf("%d", &B[i]);
	//	b[B[i]]++;
	//}
	//for (i = 0; i < 100; i++) {
	//	cnt = cnt + min(a[A[i]], b[B[i]]);
	//}
	//ans = cnt;
	////qsort(A, N, sizeof(int), compare);

	////ans = ;
	//printf("%d\n", ans);
	////printf("%s\n", max_name);

	//long long int n, i, sum = 1;
	long long n, i, sum = 1;
	scanf("%lld", &n);
	if (n == 1) //n=1????????
	{
		printf("Deficient\n");
		return 0;
	}
	for (i = 2; i <= n; i++)
	{
		if (n / i < i) //????n???????
		{
			break;
		}
		if (n == i * i) //i?n??????????
		{
			sum += i;
		}
		else if (n % i == 0) //??????
		{
			sum = sum + i + (n / i);
		}
	}
	if (sum < n) //?????
	{
		printf("Deficient\n");
	}
	else if (sum == n)
	{
		printf("Perfect\n");
	}
	else
	{
		printf("Abundant\n");
	}

#ifdef DEBUGF
	getch();
#endif
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:95:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld", &n);
  ^