#include <stdio.h>
int main() {
	int n;
	int i[8];
	char c[3] = { 'a','b','c' };
	scanf("%d", &n);
	for (i[0] = 0; i[0] < 3; i[0]++)
	{
		for (i[1] = 0; i[1] < 3; i[1]++)
		{
			for (i[2] = 0; i[2] < 3; i[2]++)
			{
				for (i[3] = 0; i[3] < 3; i[3]++)
				{
					for (i[4] = 0; i[4] < 3; i[4]++)
					{
						for (i[5] = 0; i[5] < 3; i[5]++)
						{
							for (i[6] = 0; i[6] < 3; i[6]++)
							{
								for (i[7] = 0; i[7] < 3; i[7]++)
								{
									for (int j = 8 - n; j < 8; j++)
									{
										printf("%c", c[i[j]]);
									}
									printf("\n");
								}
								if (n <= 1) break;
							}
							if (n <= 2) break;
						}
						if (n <= 3) break;
					}
					if (n <= 4) break;
				}
				if (n <= 5) break;
			}
			if (n <= 6) break;
		}
		if (n <= 7) break;
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &n);
  ^