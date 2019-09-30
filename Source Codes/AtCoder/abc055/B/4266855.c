#include <stdio.h>
#include <string.h>
#define int long long
int main(void)
{
	int n,i;
	scanf("%d",&n);
	int power=1,rest=1,quo;
	fprintf(stderr,"\n");
	for(i=1;i<=n;i++)
		{
		power = rest*i;
		rest = power%1000000007;
		quo = power/1000000007;
		if(i>=n-10){fprintf(stderr,"power=%d*(10^9+7)+%d\n",quo,rest);}
		}
	printf("%d\n",rest);
	

	
	
	

	return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:8: warning: format ‘%d’ expects argument of type ‘int *’, but argument 2 has type ‘long long int *’ [-Wformat=]
  scanf("%d",&n);
        ^
./Main.c:15:30: warning: format ‘%d’ expects argument of type ‘int’, but argument 3 has type ‘long long int’ [-Wformat=]
   if(i>=n-10){fprintf(stderr,"power=%d*(10^9+7)+%d\n",quo,rest);}
                              ^
./Main.c:15:30: warning: format ‘%d’ expects argument of type ‘int’, but argument 4 has type ‘long long int’ [-Wformat=]
./Main.c:17:9: warning: format ‘%d’ expects argument of type ‘int’, but argument 2 has type ‘long long int’ [-Wformat=]
  printf("%d\n",rest);
         ^
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^