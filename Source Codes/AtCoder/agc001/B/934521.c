#include<stdio.h>

int main()
{
	long n, x, temp1, temp2;

	scanf("%ld%ld", &n, &x);

	temp1= n;
	while(x)
	{
		temp2= n;
		n= x;
		x= temp2% x;
	}

	printf("%ld\n", (temp1- n)* 3);

	return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%ld%ld", &n, &x);
  ^