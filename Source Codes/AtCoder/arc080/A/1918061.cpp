#include<stdio.h>
#include<malloc.h>
int main(void)
{
	int f=0, t=0, ct=0, n, *a;
	scanf("%d", &n);
	a = (int*)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
		if (a[i] % 4==0) f++;
		else if (a[i] % 2 == 0) t++;
		else ct++;
	}
	if (ct - f == 1 && t == 0)
	{
		printf("Yes\n");
		return 0;
	}
	if (ct > f) printf("No\n");
	else
		printf("Yes\n");
	return 0;
}