#include<stdio.h>
long a[100000];

int main(int argc, char const *argv[]){
	long long x,y,p;
	scanf("%lld %lld\n",&x,&y);
	if(x>y){
		p=x-y;
	}else{
		p=y-x;
	}
	if(p>=2) printf("Alice\n");
	else printf("Brown\n");
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld %lld\n",&x,&y);
  ^