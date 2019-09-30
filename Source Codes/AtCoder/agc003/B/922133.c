#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef long long int type;

typedef struct array{
	type *a;
	long long int length;
} array;

array ar_init(int n){
	array a;
	a.a = calloc(sizeof(type),n);
	return a;
}
void ar_push(array* a,type x){
	a->a[a->length++] = x;
}
type ar_pop(array* a){
	return a->a[a->length--];
}
type ar_get(array* a,int n){
	return a->a[n];
}
void ar_set(array* a,int n,type x){
	a->a[n] = x;
}

int main(void){
	long long int n;
	long long int x;
	long long int sum = 0;
	long long int i;
	int mod = 0;
	array a;
	scanf("%lld",&n);
	a = ar_init(n+1);
	for(i=0;i<n;i++){
		scanf("%lld",&x);
		ar_push(&a,x);
		sum += x;
	}
	for(i=0;i<n;i++){
		if(ar_get(&a,i) % 2){
			if(ar_get(&a,i+1)){
				ar_set(&a,i+1,ar_get(&a,i+1)-1);
			}else{
				mod++;
			}
		}
	}
	printf("%lld\n", (sum-mod)/2);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:37:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld",&n);
  ^
./Main.c:40:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld",&x);
   ^