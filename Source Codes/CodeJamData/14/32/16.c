#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

char s[101][101];
int no[101];
int total;
int count;
int check[1000];

void search(int m)
{
	if (m == total)
	{
		memset(check, 0, sizeof(check));
		int last = 1000;
		for (int i = 0; i < total; i++)
		{
			int val = no[i];
			int len = strlen(s[val]);
			for (int j = 0; j < len; j++)
			{
				if (!check[s[val][j]]) check[s[val][j]] = 1;
				else if (s[val][j] != last) return;
				last = s[val][j];
			}
		}
		count++;
	}
	else for (int i = 0; i < total; i++)
	{
		if (no[i] == -1)
		{
			no[i] = m;
			search(m + 1);
			no[i] = -1;
		}
	}
	
}

int main()
{
	int n,m;
	int valid = 1;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &m);
		for (int j = 0; j < m; j++)
		{
			scanf("%s", s[j]);
		}
		total = m;
		count = 0;
		memset(no, -1, sizeof(no));
		search(0);
		printf("Case #%d: %d\n",i+1,count);
	}
}