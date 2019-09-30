#include <stdio.h>
#include <memory.h>
#include <stdlib.h>

int eval(int N, int* p, long *a, long* b){
	int i;
	for(i=0;i<N-1;i++){
			if(a[i]>=a[i+1])return 0;
			if(b[i]<=b[i+1])return 0;
			if(a[p[i]-1]+b[p[i]-1]>=a[p[i+1]-1]+b[p[i+1]-1])return 0;
			if(a[i]>=1000000000||a[i]<1)return 0;
			if(b[i]>=1000000000||b[i]<1)return 0;
	}
	return 1;
}

int makeseq(int N, int* p, long *a, long* b){
	int i;
	for(i=0;i<N;i++){
		a[i]=i*N+1;
		b[i]=(N-i-1)*N+1;
	}
	for(i=0;i<N;i++){
		a[p[i]-1]+=i;
		b[p[i]-1]+=i;
	}
	return 1;
}

int main(){
	int N, i;
	int* p;
	long* a, *b;
	scanf("%d", &N);
	p=malloc(sizeof(int)*N);
	a=malloc(sizeof(long)*N);
	b=malloc(sizeof(long)*N);
	for(i=0;i<N;i++){
		scanf("%d", &p[i]);
	}
	makeseq(N,p,a,b);
	for(i=0;i<N;i++){
		printf("%ld ", a[i]);
	}
	printf("\n");
	for(i=0;i<N;i++){
		printf("%ld ", b[i]);
	}
	printf("\n");
	//printf("%s\n", (eval(N,p,a,b)?"true":"false"));
	free(p);
	free(a);
	free(b);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:34:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &N);
  ^
./Main.c:39:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &p[i]);
   ^