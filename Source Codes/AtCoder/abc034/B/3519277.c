#include <stdio.h>
int main(void){
	long long n;
	scanf("%lld",&n);
	if(n%2==0)printf("%d\n",n-1);
	else printf("%d\n",n+1);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:19: warning: format ‘%d’ expects argument of type ‘int’, but argument 2 has type ‘long long int’ [-Wformat=]
  if(n%2==0)printf("%d\n",n-1);
                   ^
./Main.c:6:14: warning: format ‘%d’ expects argument of type ‘int’, but argument 2 has type ‘long long int’ [-Wformat=]
  else printf("%d\n",n+1);
              ^
./Main.c:4:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld",&n);
  ^