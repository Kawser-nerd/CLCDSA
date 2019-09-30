#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;
int map[3][100000];
bool flag[100000];
int get(vector<int>v)
{
	int r = 0;
	for (int i = 0; i < v.size(); i++)if (v[i] < 0)r ^= 1, v[i] = -v[i];
	for (int i = 0; i < v.size(); i++)v[i] = (v[i] - 1) / 2;
	fill(flag, flag + 100000, false);
	for (int i = 0; i < v.size(); i++)
	{
		if (!flag[i])
		{
			int now = i;
			int c = 0;
			for (;;)
			{
				if (flag[now])break;
				flag[now] = true;
				c++;
				now = v[now];
			}
			if (c % 2 == 0)r ^= 2;
		}
	}
	return r;
}
void no()
{
	printf("No\n");
	exit(0);
}
int main()
{
	int num;
	scanf("%d", &num);
	for (int i = 0; i < 3; i++)for (int j = 0; j < num; j++)scanf("%d", &map[i][j]);
	vector<int>vec;
	vector<int>v1, v2;
	for (int i = 0; i < num; i++)
	{
		if (map[0][i] + 1 == map[1][i] && map[1][i] + 1 == map[2][i] && map[2][i] % 3 == 0)vec.push_back(map[2][i] / 3);
		else if (map[2][i] + 1 == map[1][i] && map[1][i] + 1 == map[0][i] && map[0][i] % 3 == 0)vec.push_back(-map[0][i] / 3);
		else no();
	}
	for (int i = 0; i < num; i++)
	{
		if (i % 2 == 0)
		{
			if (vec[i] % 2 == 0)no();
			else v1.push_back(vec[i]);
		}
		else
		{
			if (vec[i] % 2 == 0)v2.push_back(vec[i]);
			else no();
		}
	}
	int s = get(v1), t = get(v2);
	if (((s & 1) == 0) == ((t & 2) == 0) && ((s & 2) == 0) == ((t & 1) == 0))printf("Yes\n");
	else no();
}