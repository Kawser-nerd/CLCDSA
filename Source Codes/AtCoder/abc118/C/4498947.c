#include <stdio.h>
#include <stdlib.h>

int Findgcd_by_Euclid(int, int);

int main()
{
	int monster;
	int d;
	int i;
	int gcd;
	scanf("%d", &d);

	scanf("%d", &monster);
	gcd = monster;

	for (i = 1; i < d; i++)
	{
		scanf("%d", &monster);
		gcd = Findgcd_by_Euclid(monster, gcd);
	}
	printf("%d", gcd);
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
./Main.c:14:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &monster);
  ^
./Main.c:19:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &monster);
   ^