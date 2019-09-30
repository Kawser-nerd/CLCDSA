#include <stdio.h>
int clc(int n){
	int rev_n=0;
	while(n!=0){
		rev_n*=10;
		rev_n+=n%10;
		n/=10;
	}
	return rev_n;
}
int main()
{
	int n, rev_n;
	scanf("%d", &n);
	rev_n=clc(n);
	if(n==rev_n)printf("Yes\n");
	else printf("No");
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:14:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &n);
  ^