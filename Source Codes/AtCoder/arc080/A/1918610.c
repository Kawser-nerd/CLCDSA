#include<stdio.h>
long int a[200000];
int main()
{
	long int n, i,j,k,m,b;
	k = 0;
	m = 0;
	b = 0;
	scanf("%ld", &n);
	for (i = 0;i < n;i++)
	{
		scanf("%ld", &a[i]);
		if ((a[i] % 4) == 0)
			k++;
		else
			if ((a[i]%2)==0)
				b++;
			else
				m++;
	}
	if (k >= m)
		printf("Yes");
	else
		if ((k == (m - 1)) && (b == 0)&&(k>=1))
			printf("Yes");
		  else
			printf("No");
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:9:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%ld", &n);
  ^
./Main.c:12:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%ld", &a[i]);
   ^