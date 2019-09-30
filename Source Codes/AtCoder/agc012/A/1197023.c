#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define rep(i,n) for(i=0;i<n;i++)
int in(void){
	int i;
	scanf("%d",&i);
	return i;
}
long long llin(void){
	long long i;
	scanf("%lld",&i);
	return i;
}
int cmp(const void *a,const void *b){
	return *(long long *)a-*(long long *)b;
}
long long min(long long a,long long b){
	return a<b?a:b;
}
long long max(long long a,long long b){
	return a>b?a:b;
}

long long a[300000];

int main(void){
	int i,n;
	long long ans=0;
	n=in();
	rep(i,3*n){
		a[i]=llin();
	}
	qsort(a,3*n,sizeof(long long),cmp);
	for(i=n;i<3*n;i+=2){
		ans+=a[i];
	}
	printf("%lld\n",ans);
	return 0;
} ./Main.c: In function ‘in’:
./Main.c:8:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&i);
  ^
./Main.c: In function ‘llin’:
./Main.c:13:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld",&i);
  ^