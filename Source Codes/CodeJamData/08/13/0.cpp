#include <stdlib.h>
#include <stdio.h>

int mod = 1000;

class matrix
{
public:
	int data[2][2];
};

matrix multiply(matrix a, matrix b)
{
	matrix result;
	result.data[0][0] = (a.data[0][0] * b.data[0][0] + a.data[0][1] * b.data[1][0]+ 1000000) % mod;
	result.data[0][1] = (a.data[0][0] * b.data[0][1] + a.data[0][1] * b.data[1][1]+ 1000000) % mod;
	result.data[1][0] = (a.data[1][0] * b.data[0][0] + a.data[1][1] * b.data[1][0]+ 1000000) % mod;
	result.data[1][1] = (a.data[1][0] * b.data[0][1] + a.data[1][1] * b.data[1][1]+ 1000000) % mod;
	return result;
}

matrix power(matrix a, int n)
{
	matrix result;
	result.data[0][0] = result.data[1][1] = 1;
	result.data[0][1] = result.data[1][0] = 0;
	matrix power = a;
	for (int i = 0; i <= 30; i++)
	{

		if ((n & (1 << i)) != 0)
		{
//			printf("1");
			result = multiply(result, power);
		}
//		else
//			printf("0");
		power = multiply(power, power);
	}
//	printf("\n");
	return result;
}

void print(matrix a)
{
	printf("%d %d %d %d\n", a.data[0][0], a.data[0][1], a.data[1][0], a.data[1][1]);
}

int main()
{
	matrix trans;
	trans.data[0][0] = 0;
	trans.data[0][1] = 1;
	trans.data[1][0] = -4;
	trans.data[1][1] = 6;

	int numCase, i, n;
	scanf("%d", &numCase);
	for (i = 0; i < numCase; i++)
	{
		scanf("%d", &n);
		n--;
		matrix tP = power(trans, n);
//		printf("%d\n", n);
//		print(trans);
		int res = (tP.data[0][0] * 6 + tP.data[0][1] * 28+ 1000000) % mod;
		if (res == 0) res = 999;
		else res--;
		printf("Case #%d: %03d\n", i+1, res);
	}
	return 0;
}
