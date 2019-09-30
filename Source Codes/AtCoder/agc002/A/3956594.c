#include<stdio.h>

int main(){
	long a,b;
	scanf("%ld%ld",&a,&b);
	if(a>0){
		puts("Positive");
		return 0;
	}else if(a==0||b==0){
		puts("Zero");
		return 0;
	}else {
		if(b>0){
			puts("Zero");
			return 0;
		}else {
			if((b-a)%2==0)puts("Negative");
			else puts("Positive");
			return 0;
		}
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%ld%ld",&a,&b);
  ^