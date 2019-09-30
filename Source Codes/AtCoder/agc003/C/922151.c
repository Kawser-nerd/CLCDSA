#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct vector{
	int x;
	int y;
} vector;

int comp(const void *a,const void *b){
	return (*((vector**)a))->x - (*((vector**)b))->x;
}

int main(void){
	int n;
	vector *a;
	vector **p;
	int i;
	int res = 0;
	scanf("%d",&n);
	a = calloc(sizeof(vector),n);
	p = calloc(sizeof(vector*),n);
	for(i = 0;i < n;i++){
		scanf("%d",&a[i].x);
		p[i] = &a[i];
	}
	qsort(p,n,sizeof(vector*),comp);
	for(i = 0;i < n;i++){
		p[i]->y = i;
	}
	for(i = 0;i < n;i+=2){
		if(a[i].y % 2){
			res++;
		}
	}
	printf("%d\n", res);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:20:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^
./Main.c:24:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&a[i].x);
   ^