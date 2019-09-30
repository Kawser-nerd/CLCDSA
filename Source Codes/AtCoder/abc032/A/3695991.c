#include<stdio.h>
int gcd(int a,int b)
{
	if(b==0)
	return a;
	return gcd(b,a%b);
}
int main()
{
	int a,b,n,x,temp,i=2;
	scanf("%d%d%d",&a,&b,&n);
	x=a/gcd(a,b)*b;
	temp=x;
	while(x<n)
	{
		x=temp*i;
		i++;	
	}
	printf("%d\n",x);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:11:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d%d",&a,&b,&n);
  ^