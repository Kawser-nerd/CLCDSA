#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int w, h, k, n1;
	long *n;
	long mod=1000000007;
	long b[9] = {0, 1, 1, 2, 3, 5, 8, 13, 21};
	scanf("%d%d%d", &h, &w, &k);
	n1 = w*(h+1);
	n = (long *)malloc(sizeof(long)*n1);

	n[0]=1;
	for (int i = 1; i < w; ++i)
	{
		n[i]=0;
	}
	for (int i = 1; i <= h; ++i)
	{
		for (int j = 0; j < w; ++j)
		{
			if (i<j)
			{
				n[w*i+j]=0;
			}
			else if (j==0)
			{
				n[w*i+j]=(n[w*(i-1)+j]*b[w]+n[w*(i-1)+j+1]*b[w-1]+mod)%mod;
			}
			else if (j==w-1)
			{
				n[w*i+j]=(n[w*(i-1)+j]*b[w]+n[w*(i-1)+j-1]*b[w-1]+mod)%mod;
			}
			else
			{
				n[w*i+j]=(n[w*(i-1)+j]*b[j+1]*b[w-j]+n[w*(i-1)+j-1]*b[j]*b[w-j]+n[w*(i-1)+j+1]*b[w-j-1]*b[j+1]+mod)%mod;
			}
		}
	}

	printf("%ld\n", n[w*h+k-1]);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:10:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d%d", &h, &w, &k);
  ^