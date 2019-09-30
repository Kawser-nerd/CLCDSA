#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(void)
{
	int k, c1=0, c2, p1=2, p2=1, q[20], q1, q2=0, d1=0;
	long n, m, *a, *a1, *b, *c, *d, *dd, mod=1000000007;
	scanf("%ld%ld", &n, &m);
	if (n==1 || m==1)
	{
		printf("%d\n", 1);
		return 0;
	}
	c=(long *)malloc(sizeof(long)*(int)(2*(int)sqrt(m)));
	for (long i = 1; i <= (int)sqrt(m); ++i)
	{
		if (m%i == 0)
		{
			c[c1]=i;
			c1++;
		}
	}
	for (long i = (int)sqrt(m); i >= 1; i--)
	{
		if ((int)pow(i, 2) == m) i--;
		if (m%i == 0)
		{
			c[c1]=m/i;
			c1++;
		}
	}
	while (p1 <= n) 
	{
		p1*=2;
		p2++;
	}
	p1/=2;
	b=(long *)malloc(sizeof(long)*c1*p2);
	p2--;
	for (int i = 0; i < c1*(p2+1); ++i)
	{
		b[i]=0;
	}
	for (int i = 0; i < c1; ++i)
	{
		b[i]=1;
	}
	c2=(int)pow(c1,2);
	d=(long *)malloc(sizeof(long)*c2);
	for (int i1 = 0; i1 < c1; i1++)
	{
		for (int i2 = 0; i2 < c1; i2++)
		{
			if (((m+c[i1]*c[i2])%(c[i1]*c[i2]) == 0) && (c[i1]*c[i2] <= m))
			{
				d[d1]=c1*i1+i2;
				d1++;
			}
		}
	}
	dd=(long *)malloc(sizeof(long)*d1);
	for (int i = 0; i < d1; ++i)
	{
		k=0;
		while (c[k] != c[d[i]/c1]*c[(d[i]+c1)%c1]) k++;
		dd[i] = k;
	}
	for (int i = 1; i <= p2; ++i)
	{
		for (int j = 0; j < d1; ++j)
		{
			b[c1*i+dd[j]] += b[c1*(i-1)+d[j]/c1]*b[c1*(i-1)+(d[j]+c1)%c1];
			b[c1*i+dd[j]] = (b[c1*i+dd[j]]+mod)%mod;
		}
	}
	q1=n;
	for (int i = p2; i >= 0; i--)
	{
		if (q1>=p1)
		{
			q1-=p1;
			q[q2]=i;
			q2++;
		}
		p1/=2;
	}
	a=(long *)malloc(sizeof(long)*c1);
	a1=(long *)malloc(sizeof(long)*c1);
	for (int i = 0; i < c1; ++i)
	{
		a[i]=b[c1*q[0]+i];
	}
	for (int i = 1; i <= q2-1; ++i)
	{
		for (int j = 0; j < c1; ++j)
		{
			a1[j]=0;
		}
		for (int j = 0; j < d1; ++j)
		{
			a1[dd[j]] += a[d[j]/c1]*b[c1*q[i]+(d[j]+c1)%c1];
			a1[dd[j]] = (a1[dd[j]]+mod)%mod;
		}
		for (int j = 0; j < c1; ++j)
		{
			a[j]=a1[j];
		}
	}
	printf("%ld\n", a[c1-1]);
	free(b);
	free(c);
	free(d);
	free(dd);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%ld%ld", &n, &m);
  ^