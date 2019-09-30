#include<stdio.h>
#include<math.h>
int isprime(int n)
{
	for(int i=2;i<=sqrt(n);i++)
	if(n%i==0)
	return 0;
	return 1;
}
int main()
{
	int n;scanf("%d",&n);
	if(isprime(n))
	printf("YES\n");
	else
	printf("NO\n");
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:12:8: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  int n;scanf("%d",&n);
        ^