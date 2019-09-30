#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

#define lli long long int
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
#define	abs(a) ((a)<0?-(a):(a))

typedef struct temp{
	lli a;
	lli b;
} temp;

int compd(const void *a,const void *b){
	return ((temp*)a)->a - ((temp*)b)->a;
}
int compu(const void *a,const void *b){

	return ((temp*)b)->b - ((temp*)a)->b;
}

int main(void){

	int n;
	int a,b;
	temp *u,*d;
	int u_len = 0;
	int d_len = 0;

	int i;

	lli res,t;

	scanf("%d",&n);
	d = calloc(sizeof(temp),n);
	u = calloc(sizeof(temp),n);

	for(i=0;i<n;i++){
		scanf("%d%d",&a,&b);
		if(a > b){
			u[u_len].a = a;
			u[u_len++].b = b;
		}else{
			d[d_len].a = a;
			d[d_len++].b = b;
		}
	}
	qsort(u,u_len,sizeof(temp),compu);
	qsort(d,d_len,sizeof(temp),compd);
	res = 0;t = 0;
	printf("\n");
	for(i=0;i<d_len;i++){
		t += d[i].a;
		res = max(res,t);
		t -= d[i].b;
		res = max(res,t);
	}
	printf("\n");
	for(i=0;i<u_len;i++){
		t += u[i].a;
		res = max(res,t);
		t -= u[i].b;
		res = max(res,t);
	}
	printf("%lld\n", res);

	return 0;
} ./Main.c: In function ‘main’:
./Main.c:36:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^
./Main.c:41:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&a,&b);
   ^