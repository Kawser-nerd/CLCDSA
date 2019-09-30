#include <iostream>
#include <string>
using namespace std;

int main()
{
	int i, j, icase, ncase;
	int end;
	int flag;
	char a, b, c;
	int C, D, N;
	char str[105];
	int gc[105][105], go[105][105];

	freopen("1.txt", "r", stdin);
	freopen("2.txt", "w", stdout);
	scanf("%d", &ncase);

	for(icase = 1;icase <= ncase;icase++)
	{
		scanf("%d", &C);
		getchar();
		memset(gc, 0, sizeof(gc));
		for(i = 0;i < C;i++)
		{
			scanf("%c%c%c", &a, &b, &c);
			gc[a - 'A'][b - 'A'] = gc[b - 'A'][a - 'A'] = c;
			getchar();
		}

		scanf("%d", &D);
		getchar();
		memset(go, 0, sizeof(go));
		for(i = 0;i < D;i++)
		{
			scanf("%c%c", &a, &b);
			go[a - 'A'][b - 'A'] = go[b - 'A'][a - 'A'] = 1;
			getchar();
		}

		scanf("%d", &N);
		getchar();
		end = -1;

		for(i = 0;i < N;i++)
		{
			str[++end] = getchar();

			flag = 1;
			while(flag)
			{
				flag = 0;
				if (end >= 1 && gc[str[end] -'A'][str[end - 1] - 'A'])
				{
					str[end - 1] = gc[str[end] -'A'][str[end - 1] - 'A'];
					end--;
					flag = 1;
				}
			}

			for(j = 0;j < end;j++)
				if (go[str[j] - 'A'][str[end] - 'A'])
				{
					end = -1;
					break;
				}
		}

	//	printf("%d\n", end);
		printf("Case #%d: [", icase);
		if (end >= 0)
			printf("%c", str[0]);
		for(i = 1;i <= end;i++)
			printf(", %c", str[i]);
		printf("]\n");
	}
	return 0;
}
