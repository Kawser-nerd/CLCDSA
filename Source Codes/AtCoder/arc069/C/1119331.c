#include<stdio.h>

long long s[100000];

typedef struct{
	long long a;
	long id;
} stone;
stone a[100000];

int cmp(const void *a, const void *b){
	if(((stone*)a)->a==((stone*)b)->a){
		return ((stone*)a)->id-((stone*)b)->id;
	}
	return ((stone*)b)->a-((stone*)a)->a;
}

int main(int argc, char const *argv[]) {
	long n,i;
	long long max;
	scanf("%ld",&n);
	for(i=0;i<n;i++){
		scanf("%lld",&a[i].a);
		a[i].id=i;
	}
	qsort(a,n,sizeof(stone),cmp);
	max=a[0].a;
	for(i=0;i<n;i++){
		if(max!=a[i].a){
			s[a[0].id]+=i*(max-a[i].a);
			if(a[0].id>a[i].id) a[0].id=a[i].id;
			max=a[i].a;
		}
	}
	s[0]+=((long long)n)*max;
	for(i=0;i<n;i++){
		printf("%lld\n",s[i]);
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:26:2: warning: implicit declaration of function ‘qsort’ [-Wimplicit-function-declaration]
  qsort(a,n,sizeof(stone),cmp);
  ^
./Main.c:21:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%ld",&n);
  ^
./Main.c:23:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld",&a[i].a);
   ^