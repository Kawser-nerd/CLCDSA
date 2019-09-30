#include <stdio.h>

int main()
{
	int notc;
	scanf("%d", &notc);
	for(int nc=1; nc <= notc; nc++)
	{
		long long n , k;
		scanf("%lld %lld", &n, &k);
		int temp[50];
		int len = 0;
		long long rem = k;
		while(1)
		{
			temp[len] = rem % 2;
			rem = rem / 2;
			len++;
			if(rem == 0)
				break;
		}

		temp[len-1] = 0;
		long long num1 = n;
		long long num2 = n;
		long long num = n;

		for(int i = -1; i < len-1; i++) {
			num1 = num/2;
			num2 = num - 1 - (num/2);
			num = num1;
			if(temp[i+1] == 1)
			{
				num = num2;
			}
		}
		printf("Case #%d: %lld %lld\n", nc, num1, num2);
	}
	return 0;
}
