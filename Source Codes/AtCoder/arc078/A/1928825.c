#include<stdio.h>
#include<stdlib.h>


int main()
{
	int n;
	scanf("%d", &n);
		 
	long long int *a = NULL;
	a = (long long int *)malloc(sizeof(long long int)*n);
	long long int *b = NULL;
	b = (long long int *)malloc(sizeof(long long int)*n);
	int i;
	long long int s = 0;
	for (i = 0; i < n; i++)
	{
		scanf("%lld", &a[i]);
		s += a[i];
	 }
	long long int t = 0,m;
		 
	for (i = 0; i<n;i++)
	{
		t += a[i];
		if (s - 2 * t >= 0) b[i] = s - 2 * t;
		else b[i]=2*t-s;
	}
	m = b[0];
	for (i = 0; i < n-1; i++)
		if (b[i] < m)m = b[i];

	
	printf("%lld\n", m);
	free(a);
	free(b);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &n);
  ^
./Main.c:18:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld", &a[i]);
   ^