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
	int n,n1,sum=0;
	scanf("%d",&n);
	if(n==1)
	printf("Not Prime\n");
	else{
		n1=n;
		while(n1>0)
		{
			sum+=n1%10;
			n1/=10;
		}
		if(isprime(n)==1||(isprime(n)==0&&n%5!=0&&sum%3!=0&&n%2!=0))
		printf("Prime\n");
		else 
		printf("Not Prime\n");
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:13:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^