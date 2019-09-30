#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n;
	scanf("%d", &n);
	int c[505];
	int s[505];
	int f[505];
	int t[505];
	int i, j;
	for (i = 0; i < n-1; i++)
	{
		scanf("%d%d%d", c+i,s+i,f+i);
		t[i] = s[i];
	}
	for (i = 0; i < n-1; i++)
	{
		for (j = i; j < n-1; j++)
		{
			while (!(t[i] % f[j] == 0) || t[i] < s[j])
			{
				t[i]++;
			}
			t[i] += c[j];
		}
	}
	for (i = 0; i < n-1; i++)
		printf("%d\n", t[i]);
	printf("0\n");
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &n);
  ^
./Main.c:14:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d", c+i,s+i,f+i);
   ^