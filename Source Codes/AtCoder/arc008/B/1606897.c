#include<stdio.h>

int main()
{
	int n, m, i, cnt = 1;
	char name[51], kit[51];

	scanf("%d%d%s%s", &n, &m, name, kit);

	for(i = 'A'; i <= 'Z'; i++)
	{
		int name_t = 0, kit_t = 0, j;

		for(j = 0; j < n; j++)
			if(name[j] == i)
				name_t++;

		for(j = 0; j < m; j++)
			if(kit[j] == i)
				kit_t++;

		if(name_t >= 1 && kit_t == 0)
		{
			cnt = -1;
			break;
		}

		while(name_t > kit_t * cnt)
			cnt++;
	}

	printf("%d\n", cnt);

	return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d%s%s", &n, &m, name, kit);
  ^