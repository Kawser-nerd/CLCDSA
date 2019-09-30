#include <stdio.h>
#include <stdlib.h>

void mergesort(long y[], int p[], int a[], int i, int j);
void merge(long y[], int p[], int a[], int i, int j);

int main(void)
{
	int n, m, *p, *a;
	long *y, *no, *c;
	scanf("%d%d", &n, &m);
	p=(int *)malloc(sizeof(int)*m);
	y=(long *)malloc(sizeof(long)*m);
	a=(int *)malloc(sizeof(int)*m);
	no=(long *)malloc(sizeof(long)*m);
	c=(long *)malloc(sizeof(long)*(n+1));

	for (int i = 0; i < m; ++i)
	{
		scanf("%d%ld", &p[i], &y[i]);
	}
	for (int i = 0; i < m; ++i)
	{
		a[i] = i;
	}
	for (int i = 0; i <= n; ++i)
	{
		c[i] = 1;
	}

	mergesort(y, p, a, 0, m-1);

	for (int i = 0; i < m; ++i)
	{
		no[a[i]] = (long)p[i]*1000000+c[p[i]];
		c[p[i]]++;
	}

	for (int i = 0; i < m; ++i)
	{
		printf("%012ld\n", no[i]);
	}

	free(y);
	free(p);
	free(a);
	free(no);
	free(c);

	return 0;
}

void mergesort(long y[], int p[], int a[], int i, int j)
{
	if (i-j == 0)
	{
		return;
	}
	else
	{
		mergesort(y, p, a, i, (i+j)/2);
		mergesort(y, p, a, (i+j)/2+1, j);
		merge(y, p, a, i, j);
		return;
	}
}

void merge(long y[], int p[], int a[], int i, int j)
{
	int l, r;
	long y2[j];
	int p2[j];
	int a2[j];
	l=i;
	r=(i+j)/2+1;
	for (int k = i; k <= j; ++k)
	{
		if (l > (i+j)/2)
		{
			y2[k] = y[r];
			p2[k] = p[r];
			a2[k] = a[r];
			r++;
		} else if (r > j)
		{
			y2[k] = y[l];
			p2[k] = p[l];
			a2[k] = a[l];
			l++;
		} else if (y[l] <= y[r])
		{
			y2[k] = y[l];
			p2[k] = p[l];
			a2[k] = a[l];
			l++;
		} else
		{
			y2[k] = y[r];
			p2[k] = p[r];
			a2[k] = a[r];
			r++;
		}
	}
	for (int k = i; k <= j; ++k)
	{
		y[k]=y2[k];
		p[k]=p2[k];
		a[k]=a2[k];
	}
	return;
} ./Main.c: In function ‘main’:
./Main.c:11:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d", &n, &m);
  ^
./Main.c:20:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%ld", &p[i], &y[i]);
   ^