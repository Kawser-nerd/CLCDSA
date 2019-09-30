#include <stdio.h>
#include <stdlib.h>

typedef struct rope{
	long long int len;
	int connect;
}rope;

int main(){
	int i,key = 0;
	int n;
	long long int l;
	rope *a;
	int *res;
	int res_length = 0;
	scanf("%d %lld",&n,&l);
	a = calloc(sizeof(rope),n+1);
	res = calloc(sizeof(rope),n);

	for(i = 1;i <= n;i++){
		scanf("%lld",&(a[i].len));
		a[i].connect = 1;
	}
	for(i = 1;i < n;i++){
		if(a[i].len + a[i+1].len >= l){
			key = i;
			break;
		}
	}
	if(!key){
		printf("Impossible\n");
		return 0;
	}else{
		printf("Possible\n");
	}
	for(i = 1;i < key;i++){
		res[res_length++] = i;
	}
	for(i = n-1;i > key;i--){
		res[res_length++] = i;
	}
	res[res_length++] = key;
	for(i = 0;i < res_length;i++){
		printf("%d\n", res[i]);
	}


	return 0;
} ./Main.c: In function ‘main’:
./Main.c:16:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %lld",&n,&l);
  ^
./Main.c:21:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld",&(a[i].len));
   ^