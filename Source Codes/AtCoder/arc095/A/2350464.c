#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int i;
	int x;
	int m;
} T_DATA;
T_DATA a[200000] = {0};

int comp1(const void* p1, const void* p2)
{
	return ((T_DATA*)p1)->x - ((T_DATA*)p2)->x;
}
int comp2(const void* p1, const void* p2)
{
	return ((T_DATA*)p1)->i - ((T_DATA*)p2)->i;
}
int main(int argc, char** argv)
{
	int n;
	int i;
	int d;
	
	scanf("%d", &n);
	for(i=0;i<n;++i){
		int k;
		scanf("%d", &k);
		a[i].x = k;
		a[i].i = i;
	}
	//sort
	qsort(a, n, sizeof(*a), comp1);
	
	for(i=0; i<n/2; ++i){
		a[i].m = a[n/2].x;
	}
	for(i=n/2; i<n; ++i){
		a[i].m = a[n/2-1].x;
	}
	//sort
	qsort(a, n, sizeof(*a), comp2);
	
	for(i=0; i<n; ++i){
		printf("%d\n", a[i].m);
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:25:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &n);
  ^
./Main.c:28:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &k);
   ^