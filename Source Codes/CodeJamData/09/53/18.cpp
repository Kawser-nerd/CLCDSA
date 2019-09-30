
	#include <cstdlib>
	#include <cstdio>
	#include <algorithm>

	using namespace std;

	int n, x[1005], y[1005], xx[35][1005], num[35], color[35][1005], flag;

	void init()
	{
		scanf("%d", &n);
		for (int i = 0; i < n; i ++)
			scanf("%d%d", &x[i], &y[i]);
	}

	int abs(int x)
	{
		if (x > 0)	return x;
		else	return -x;
	}

	int ok1()
	{
		for (int i = 0; i < n; i ++)
			for (int j = i + 1; j < n; j ++)
				if (abs(y[i] - y[j]) <= 1)
					return 0;
		return 1;
	}

	int ok2()
	{
		for (int i = 1; i < 30; i ++)
			if (num[i] >= 2 && num[i + 1] >= 2)
				return 0;
		for (int i = 1; i < 30; i ++)
			if (num[i] >= 2)
				if (num[i + 1] == 1 && xx[i + 1][1] > xx[i][1])
					return 0;
		for (int i = 2; i <= 30; i ++)
			if (num[i] >= 2)
				if (num[i - 1] == 1 && xx[i - 1][1] > xx[i][1])
					return 0;
		return 1;
	}

	int can1(int c1, int c2)
	{
//		printf("%d %d\n", c1, c2);
		int last = 0;
		for (int i = 1; i < num[c1]; i ++)
		{
			while (last < num[c2] && xx[c2][last] < xx[c1][i])	last ++;
			if (xx[c2][last] < xx[c1][i])	continue;
			int sum = 0;
			if (color[c1][i] == 0)	sum ++;
			if (color[c1][i + 1] == 0)	sum ++;
			if (color[c2][last] == 0)	sum ++;
		//	printf("%d\n", sum);
		//	printf("%d %d\n", c1, i);
		//	printf("%d %d\n", c1, i + 1);
		//	printf("%d %d\n", c2, last);
		//	printf("%d\n", color[c1][i]);
		//	printf("%d\n", color[c1][i + 1]);
		//	printf("%d\n", color[c2][last]);
			if (sum == 0)
			{
				if (color[c1][i] + color[c1][i + 1] + color[c2][last] == 6)	continue;
				if (color[c1][i] != color[c1][i + 1] && color[c1][i] != color[c2][last] && color[c1][i + 1] != color[c2][last])	continue;
				flag = 1;
				return 0;
			}
			if (sum == 1)
			{
				int u = 6 - color[c1][i] - color[c1][i + 1] - color[c2][last];
				if (u < 1 || u > 3)
				{
					flag = 1;
					return 0;
				}
				if (color[c1][i] == 0)	color[c1][i] = u;
				if (color[c1][i + 1] == 0)	color[c1][i + 1] = u;
				if (color[c2][last] == 0)	color[c2][last] = u;
				return 1;
			}
		}
		return 0;
	}

	int can(int col)
	{
		if (can1(col, col - 1))	return 1;
		if (flag == 1)	return 0;
		if (can1(col - 1, col))	return 1;
		return 0;
	}

	int check(int col)
	{
		return 1;
	}

	int ok3()
	{
		for (int i = 1; i <= 30; i ++)
		{
//			printf("%d\n", i);
			if (num[i] == 0)	continue;
			if (num[i - 1] == 0)
			{
				color[i][1] = 1;
				if (num[i] > 1)	color[i][2] = 2;
				continue;
			}
			if (num[i - 1] == 1)
			{
				int c = 1;
				for (int j = 1; j <= num[i] && xx[i][j - 1] < xx[i - 1][1]; j ++)
				{
					color[i][j] = c;
					c = 3 - c;
				}
				continue;
			}
			if (num[i - 1] >= 2)
			{
				flag = 0;
				while (can(i));
				if (flag == 1)	return 0;
				if (check(i))	continue;
				return 0;
			}
		}
		return 1;
	}

	int work()
	{
		init();
		if (ok1())	return 1;
		memset(num, 0, sizeof(num));
		memset(xx, 0, sizeof(xx));
		for (int i = 0; i < n; i ++)
		{
			num[y[i]] ++;
			xx[y[i]][num[y[i]]] = x[i];
		}
		for (int i = 1; i <= 30; i ++)
			for (int j = 1; j <= num[i]; j ++)
				for (int k = j + 1; k <= num[i]; k ++)
					if (xx[i][j] > xx[i][k])
					{
						int tmp = xx[i][j];
						xx[i][j] = xx[i][k];
						xx[i][k] = tmp;
					}
		memset(color, 0, sizeof(color));
		if (ok2())	return 2;
		if (ok3())	return 3;
		return 4;
	}

	int main()
	{
		freopen("c.in", "r", stdin);
		freopen("c.out", "w", stdout);
		int testnum;
		scanf("%d", &testnum);
		for (int i = 1; i <= testnum; i ++)
			printf("Case #%d: %d\n", i, work());
		return 0;
	}
