#include<stdio.h>
int main()
{
	int n, c[500], s[500], f[500];
	scanf("%d", &n);
	int i = 0;
	for ( i = 0; i < n - 1; i++)
		scanf("%d%d%d", &c[i], &s[i], &f[i]);
	for (i = 0; i < n; i++)
	{
		int t = 0;
		int j;
		for (j = i; j < n - 1; j++)
		{
			if(t < s[j])t = s[j];
			else if (t%f[j] == 0);
			else t = t + f[j] - t % f[j];
			t += c[j];
		}
		printf("%d\n", t);
	}
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &n);
  ^
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d", &c[i], &s[i], &f[i]);
   ^