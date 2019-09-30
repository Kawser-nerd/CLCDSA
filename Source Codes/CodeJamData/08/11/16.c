#include <stdio.h>
#include <stdlib.h>

int min;
int vlen;
int v1[800];
int v2[800];

int readInt(int, int, char*);

void permute_v1(int);
void permute_v2(int);
void checkEm();


int higher(const void* a, const void* b)
{
	int *aa = (int*) a;
	int *bb = (int*) b;
	return *aa - *bb;
}

int lower(const void* a, const void* b)
{
	int *aa = (int*) a;
	int *bb = (int*) b;
	return *bb - *aa;
}

int
main()
{
	int i;
	int j;
	int T;

	T = readInt(0, 1000, "test cases");

	for(i = 1; i <= T; i++) {
		vlen = readInt(0, 800, "vector length");

		for(j = 0; j < vlen; j++) {
			scanf("%d", &v1[j]);
		}

		for(j = 0; j < vlen; j++) {
			scanf("%d", &v2[j]);
		}

#if 0
		printf("T = %d\n", i);
		printf("n = %d\n", vlen);
		for(j = 0; j < vlen; j++) {
			printf("%d ", v1[j]);
		}
		printf("\n");
		for(j = 0; j < vlen; j++) {
			printf("%d ", v2[j]);
		}
		printf("\n");

		permute_v1(vlen - 1);
#endif
		qsort(v1, vlen, sizeof(int), higher);
		qsort(v2, vlen, sizeof(int), lower);

		min = 2147483647;
		checkEm();

		printf("Case #%d: %d\n", i, min);

	}
	return 0;
}

void
checkEm()
{
	int i;
	int j;
	int sum = 0;

	for(i = 0; i < vlen; i++) {
		sum = sum + v1[i] * v2[i];
	}
	if(sum < min) {
		min = sum;
#if 0
		printf("sum = %d\n", sum);
		printf("v1: ");
		for(j = 0; j < vlen; j++) {
			printf("%d ", v1[j]);
		}
		printf("\n");

		printf("v2: ");
		for(j = 0; j < vlen; j++) {
			printf("%d ", v2[j]);
		}
		printf("\n");
#endif
	}

}

void
permute_v1(int n)
{
	int i;
	int temp;

	if(n == 0) {
		permute_v2(vlen - 1);
	} else {
		permute_v1(n - 1);
		for(i = 0; i < n; i++) {
			temp = v1[i];
			v1[i] = v1[n];
			v1[n] = temp;
			permute_v1(n - 1);
			temp = v1[i];
			v1[i] = v1[n];
			v1[n] = temp;
		}
	}
}

void
permute_v2(int n)
{
	int i;
	int temp;

	if(n == 0) {
		checkEm();
	} else {
		permute_v2(n - 1);
		for(i = 0; i < n; i++) {
			temp = v1[i];
			v1[i] = v1[n];
			v1[n] = temp;
			permute_v2(n - 1);
			temp = v1[i];
			v1[i] = v1[n];
			v1[n] = temp;
		}
	}
}



int
readInt(int lo, int hi, char* what)
{
	int n;
	int c = scanf(" %d \n", &n);

	if(c != 1) {
		printf("scanf returned %d instead of 1 for %s\n", c, what);
		exit(1);
	}
	if(n < lo) {
		printf("scanf read %d, less than %d, for %s\n", n, lo, what);
		exit(1);
	}
	if(n > hi) {
		printf("scanf read %d, greater than %d, for %s\n", n, hi, what);
		exit(1);
	}
	return n;
}
