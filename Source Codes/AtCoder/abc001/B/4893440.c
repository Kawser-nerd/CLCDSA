#include <stdio.h>

int main()
{
	int m = 0;
	int vv = 0;
	scanf("%d", &m);

	if (m < 100)
	{
		printf("%02d\n",vv);
	}
	else if (100 <= m && m <= 5000)
	{
		vv = m / 100;
		printf("%02d\n", vv);
	}
	else if (6000 <= m && m <= 30000)
	{
		m = m + 50000;
		vv = m / 1000;
		printf("%02d\n", vv);

	}
	else if (35000 <= m && m <= 70000)
	{
		m = m / 1000;
		vv = (m - 30) / 5 + 80;
		printf("%02d\n", vv);
	}
	else if (m > 70000)
	{
		vv = 89;
		printf("%02d\n", vv);

	}


} ./Main.c: In function ‘main’:
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &m);
  ^