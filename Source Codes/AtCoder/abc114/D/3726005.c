#include <stdio.h>
#include <math.h>

int main(int argc, char const *argv[])
{
	int n, n1=1, n2, a[100], a1, b[100], i1=1, i2, ans=0, flag;
	scanf("%d", &n);
	if (n<10)
	{
		printf("%d\n", 0);
		return 0;
	}
	for (int i = 0; i < 100; ++i)
	{
		b[i]=0;
	}
	a[0]=2;
	for (int i = 3; i <= n; ++i)
	{
		flag=0;
		for (int j = 0; j < i1; ++j)
		{
			if (i%a[j]==0) flag=1;
		}
		if (flag==0)
		{
			a[i1]=i;
			i1++;
		}
	}
	for (int i = 0; i < i1; ++i)
	{
		a1=a[i];
		while (a1<=n)
		{
			b[i]+=n/a1;
			a1*=a[i];
		}
	}
	for (int i = 0; i < i1; ++i)
	{
		for (int j = i+1; j < i1; ++j)
		{
			for (int k = 0; k < i1; ++k)
			{
				if (k!=i && k!=j)
				{
					if (b[i]>=4 && b[j]>=4 && b[k] >=2) ans++;
				}
			}
		}
	}
	for (int i = 0; i < i1; ++i)
	{
		for (int j = 0; j < i1; ++j)
		{
			if (j>7) break;
			if (j!=i)
			{
				if (b[i]>=4 && b[j]>=14) ans++;
			}
		}
	}
	for (int i = 0; i < i1; ++i)
	{
		for (int j = 0; j < i1; ++j)
		{
			if (j>5) break;
			if (j!=i)
			{
				if (b[i]>=2 && b[j]>=24) ans++;
			}
		}
	}
	for (int i = 0; i < i1; ++i)
	{
		if (b[i]>=74) ans++;
	}
	printf("%d\n", ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &n);
  ^