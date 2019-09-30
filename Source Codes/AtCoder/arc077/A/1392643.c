#include<stdio.h>
long a[200000];
int main(int argc, char const *argv[]){
	long n,i;
	scanf("%ld",&n);
	for(i=0;i<n;i++){
		scanf("%ld",&a[i]);
	}
	if(n%2==0){
		for(i=n-1;i>0;i-=2){
			printf("%ld ",a[i]);
		}
		printf("%ld",a[0]);
		for(i=2;i<n;i+=2){
			printf(" %ld",a[i]);
		}
	}else{
		for(i=n-1;i>0;i-=2){
			printf("%ld ",a[i]);
		}
		printf("%ld",a[0]);
		for(i=1;i<n;i+=2){
			printf(" %ld",a[i]);
		}
	}
	printf("\n");
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%ld",&n);
  ^
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%ld",&a[i]);
   ^