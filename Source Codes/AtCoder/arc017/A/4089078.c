#include<stdio.h>
const int a[6]={0,2,3,7,61,24251};
long long n;
int i;

long long multi(long long a,long long b)
{
	long long sum;
	sum=0;
	while (b!=0)
	{
		if (b%2==1)
		  sum=(sum+a)%n;
		a=(a+a)%n;
		b=b/2;
	}
	return sum;
}

long long power(long long a,long long b)
{
	long long x;
	if (b==1)
	  return a;
	x=power(a,b/2);
    if (b%2==0)
      return multi(x,x);
    else
      return multi(multi(x,x),a);
}

int isprime(long long n,int a)
{
	long long d,sum;
	int i,r;
	d=n-1;
	r=0;
	while (d%2==0)
	{
		r++;
		d=d/2;
	}
	sum=power(a,d);
	if (sum==1 || sum==n-1)
	  return 1;
	for (i=1;i<=r;i++)
	{
	    sum=multi(sum,sum);
	    if (sum==n-1)
	      return 1;
	}
	return 0;
}

int main()
{
    scanf("%lld",&n);
    for (i=1;i<=5;i++)
      if (a[i]<n)
      {
	      if (isprime(n,a[i])==0)
	      {
	          printf("NO\n");
	          return 0;
	      }
	  }
	  else
	    break;
	printf("YES\n");
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:57:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lld",&n);
     ^