#include<stdio.h>

int main(){
	long n,a,c=0;
	scanf("%ld",&n);
	while(n-->0){
		scanf("%ld",&a);
		c+=a%2;
	}
	if(c%2==0)puts("YES");
	else if(n%2==1)puts("YES");
	else puts("NO");
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%ld",&n);
  ^
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%ld",&a);
   ^