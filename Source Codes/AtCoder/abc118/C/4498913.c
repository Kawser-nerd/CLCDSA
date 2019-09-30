#include <stdio.h>
#include <stdlib.h>

int Findgcd_by_Euclid(int a, int b);

int main()
{
	int monster;
	int d;
	int i;
	int gcd = 0;
	scanf("%d", &d);

	for (i = 0; i < d; i++)
	{
		scanf("%d", &monster);
		gcd = Findgcd_by_Euclid(gcd ,monster);
	}
	printf("%d\n", gcd);
	return 0;
}

int Findgcd_by_Euclid(int a, int b)
{
	int c;
	while (b)
	{
		c = a % b;
		a = b;
		b = c;
	}
	return a;
} ./Main.c: In function ‘main’:
./Main.c:12:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &d);
  ^
./Main.c:16:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &monster);
   ^